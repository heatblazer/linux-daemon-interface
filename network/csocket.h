#ifndef CSOCKET
#define CSOCKET

// custom generics
#include "defs.h"

// thrading api
#include "async/cthread.h"



class CSocket
{
private:
    // simple adding mechanism for a callstack
    struct node {
        int (*cb)(const char*);
        void*   userdata;
        struct node* next;
    };

    struct node*   p_head;

    void push(int (*cb)(const char*), void *pdata);
    void pop(struct node** pRet);

public:
    CSocket();
    virtual ~CSocket();

    void*   get_in_address(struct sockaddr* addr);
    int     Connect(const char* host, const char *port);
    int     Bind(const char* host, const char *port);

    int     Send(const char* msg);
    int     Recieve(void);

    static void*    run(void* pdata);


private:
    static int _privateSend(const char* msg);

public:
    // static control variable
    static bool     m_isRunning;
private:
    char*   getIPByName(const char* host);

protected:
private:

    static int     m_socketFd;
    union {
        sockaddr_in     ipv4;
        sockaddr_in6    ipv6;
    } m_address;


    CXThread            m_thread;
    pthread_mutex_t     m_mutex;

};

#endif // CSOCKET

