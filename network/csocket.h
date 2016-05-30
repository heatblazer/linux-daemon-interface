#ifndef CSOCKET
#define CSOCKET

// custom generics
#include "defs.h"

// thrading api
#include "async/cthread.h"



class CSocket
{

// custom stack based interface
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
    virtual ~CSocket(); // do we need to inherit sth. from this class?


    // virtual methods
    virtual void*   get_in_address(struct sockaddr* addr);

    // connect to a host
    virtual int     Connect(const char* host, const char *port);

    // use as server
    virtual int     Bind(const char* host, const char *port);

    // send and recieve metods
    virtual int     Send(const char* msg);
    virtual int     Recieve(void);


    //! The thread callback
    //! \brief run
    //! \param pdata
    //! \return
    //!
    static void*    run(void* pdata);

public:
    // static control variable
    static bool     m_isRunning;
private:

    static int _privateSend(const char* msg);
    char*   getIPByName(const char* host);

protected:
private:

    enum ClienServer { CLIENT, SERVER, MAX };

    static int     m_sockets[ClienServer::MAX];

    // ipv4 or ipv6
    union {
        sockaddr_in     ipv4;
        sockaddr_in6    ipv6;
    } m_address[ClienServer::MAX];


    CXThread            m_thread;
    pthread_mutex_t     m_mutex;

};

#endif // CSOCKET

