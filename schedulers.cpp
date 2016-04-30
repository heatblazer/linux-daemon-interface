#include "schedulers.h"
#include <stdlib.h>

/////////////////////////////////////////////////

///Opaques
///
typedef struct _n
{
    char* tname;
    void* pData;
    struct _n* next;
} node;

//////////////////////////////////////////////////

///Statics
///
pthread_mutex_t RoundRobin::m_mutex ;

node*           RoundRobin::m_head = 0;
//////////////////////////////////////////////////


/**
 * @brief adds and fetches atomic integer
 * @param pointer to integer
 * @param incremet value, +1 in most cases
 * @return the inc value
 */
static inline int fetch_and_add(int* pAtomic, int value)
{
    //the x86 atomic add and fetch(ret) value
    //the 32 bit regs int is atomic by all means
    asm volatile ("lock; xaddl %%eax, %2;"
                  :"=a"(value)
                  :"a" (value), "m" (*pAtomic)
                  :"memory");
    return value;
}

/**
 * @brief locked push to list
 * @param pointer to the linked list struct
 * @param the data to insert
 */
void RoundRobin::atomic_push(node **pNode, void *pData)
{
    pthread_mutex_lock(&RoundRobin::m_mutex);
    critical_section:
    {
        node* n = (node*) malloc(sizeof(node));
        n->pData = pData;
        n->next = (*pNode);
        (*pNode) = n;
    } //leave crit section
    pthread_mutex_unlock(&RoundRobin::m_mutex);
}


/**
 * @brief the callback accessed by threads
 * @param pointer to user data
 * @return return value
 */
void* RoundRobin::run(void* pdata)
{
    RoundRobin::atomic_push(&m_head, pdata);
}


/**
 * @brief RoundRobin::RoundRobin constructor and init mutex
 */
RoundRobin::RoundRobin()
{
    pthread_mutex_init(&m_mutex, NULL);
}

/**
 * @brief RoundRobin::~RoundRobin the destructor
 */
RoundRobin::~RoundRobin()
{

}


/**
 * @brief creates N threads, no args passing for now, test function
 */
void RoundRobin::start(void)
{
    int i = 0;
    static char tname[64]= {0};

    for(i=0; i < MAX_NUM_THREADS; ++i) {
        sprintf(tname, "Thread%d", i);
        pthread_setname_np(m_threads[i], tname);
    }

    for(i=0; i < MAX_NUM_THREADS; ++i) {
        pthread_create(&m_threads[i], NULL, RoundRobin::run, NULL);
    }
}


/**
 * @brief joins all threads before destroying the RR
 */
void RoundRobin::stop(void)
{
    int i = 0;
    for(i=0; i < MAX_NUM_THREADS; ++i) {
        pthread_join(m_threads[i], NULL); //no rets
    }
}

