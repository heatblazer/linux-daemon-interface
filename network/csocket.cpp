#include "csocket.h"

// ANSI C
#include <string.h>
#include <stdlib.h>


bool CSocket::m_isRunning = true;
int CSocket::m_socketFd = 0;

CSocket::CSocket() : p_head(0)
{
    pthread_mutex_init(&m_mutex, 0);
}


CSocket::~CSocket()
{

}

//! NOTE Unused for now
//! \brief CSocket::get_in_address
//! \param addr
//! \return
//!
void*   CSocket::get_in_address(struct sockaddr *addr)
{
    if (addr->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)addr)->sin_addr);
    } else {
        return &(((struct sockaddr_in6*)addr)->sin6_addr);
    }
}

//! Resolve host name by name ex. google.com
//! \brief CSocket::getIPByName
//! \param host
//! \return
//!
char*   CSocket::getIPByName(const char *host)
{
    static char ip[100] = {0};
    memset(ip, 0, sizeof(ip)/sizeof(char));

    struct hostent* he;
    struct in_addr** addr_list;
    int i;

    if ((he = gethostbyname(host)) == NULL) {
        return NULL;
    }

    addr_list = (struct in_addr**) he->h_addr_list;
    for(i=0; addr_list[i] != NULL; i++) {
        strcpy(ip, inet_ntoa(*addr_list[i]));
    }

    return ip;
}


//! Sicket init and connect also init the thread
//! \brief CSocket::Connect
//! \param host
//! \param port
//! \return
//!
int    CSocket::Connect(const char *host, const char* port)
{

    m_socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socketFd < 0) {
        return -1;
    }

    m_address.ipv4.sin_addr.s_addr = inet_addr(host);
    m_address.ipv4.sin_family = AF_INET;
    m_address.ipv4.sin_port = htons((uint16_t) atoi(port));

    if (connect(m_socketFd, (struct sockaddr*)&m_address.ipv4,
                sizeof(m_address.ipv4)) < 0 ) {
        return -1;
    }


    // move the threads elsewhere, since we`ll stick here
    // before we got loged in
    m_thread.init(1024 * 1024, CSocket::run, this);

    return 0;
}

//! TODO: implement
//! \brief CSocket::Bind
//! \param host
//! \param port
//! \return
//!
int CSocket::Bind(const char *host, const char* port)
{
    return -1;

}


//! The function to be pushed on the call stack
//! \brief CSocket::_privateSend
//! \param msg
//! \return
//!
int CSocket::_privateSend(const char *msg)
{
    if (send(m_socketFd, msg, strlen(msg), 0) < 0) {
        return -1;
    }

}

//! push the private function to the call list
//! \brief CSocket::Send
//! \param msg
//! \return
//!
int CSocket::Send(const char *msg)
{
    push(_privateSend, (void*)msg);
    return 0;
}



//! the buff is fixed, which is OK ( see in the web usage of recv(...) )
//! \brief CSocket::Recieve
//! \return -1 on fail 0 on success
//!
int CSocket::Recieve()
{
    char buff[3000] = {0};

    if (recv(m_socketFd, buff, sizeof(buff), 0) < 0) {
        return -1;
    }
    // this is test - remove it later!!!
    puts(buff);
    puts("\n");
    return 0;
}


// privates inner
void CSocket::push(int (*cb)(const char *), void *pdata)
{
//    pthread_mutex_lock(&m_mutex);
    ENTER_CRITICAL_SECTION
    struct CSocket::node* pnode = (struct CSocket::node*)
            malloc(sizeof(struct CSocket::node*));
    if (pnode == NULL) {
        // omit
    } else {
        pnode->cb = cb;
        pnode->userdata = pdata;
        pnode->next = p_head;
        p_head = pnode;
    }
    //pthread_mutex_unlock(&m_mutex);
    LEAVE_CRITICAL_SECTION
}


void CSocket::pop(struct CSocket::node** pRet)
{
    ENTER_CRITICAL_SECTION

    struct CSocket::node* pnode = 0;
    if (p_head != 0) {
        pnode = p_head;
        (*pRet) = pnode;
        if (p_head != 0 ) {
            p_head = p_head->next;
            free(p_head);
        }

    }
    LEAVE_CRITICAL_SECTION

}


//! The runnable function
//! \brief CSocket::run
//! \param pdata
//! \return
//!
void*    CSocket::run(void *pdata)
{
    CSocket* s = (CSocket*) pdata;
    s->Send("Action: Login\nUsername: joro\nSecret: sopa123\n\n");

    static pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, 0);

    while (CSocket::m_isRunning) {
        // pop the stack and call it
        if (!m_isRunning) {
            break;
        }
        // use mutex locks for now
        pthread_mutex_lock(&mutex);
        struct CSocket::node* pnode = 0;
        s->pop(&pnode);
        if (pnode != 0) {
            pnode->cb((char*)pnode->userdata);
            s->Recieve();
        }
        pthread_mutex_unlock(&mutex);
    }
}





