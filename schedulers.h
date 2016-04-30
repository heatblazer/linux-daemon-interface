#ifndef SCHEDULERS
#define SCHEDULERS
#include "defs.h"
#include <pthread.h>


class RoundRobin;
class CASLockFree;
typedef struct _n node; //opaque aggregate structure

//abstract class
class RoundRobin
{
    virtual ~RoundRobin();
    RoundRobin();

    static  void* run(void* pdata); //the running function
    virtual void start(void);
    virtual void stop(void);

private:
    //
    static void  atomic_push(node** pNode, void* pData);

    static pthread_mutex_t  m_mutex;
    pthread_t               m_threads[MAX_NUM_THREADS];
    static node*                   m_head; //the list of data
};


#endif // SCHEDULERS

