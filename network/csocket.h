#ifndef CSOCKET
#define CSOCKET

// custom generics
#include "defs.h"

// thrading api
#include "async/cthread.h"

class CSocket
{
public:
    CSocket();
    virtual ~CSocket();

    virtual void*   get_in_address(struct sockaddr* addr);
    virtual int     Connect(const char* host, const char *port);
    virtual int     Bind(const char* host, const char *port);



    virtual int     Send(const char* msg);
    virtual int     Recieve(void);

    static void*    run(void* pdata);

public:
    // static control variable
    static bool     m_isRunning;
private:

    char*   getIPByName(const char* host);

protected:
private:

    int     m_socketFd;
    union {
        sockaddr_in     ipv4;
        sockaddr_in6    ipv6;
    } m_address;


    CXThread            m_thread;


};


#endif // CSOCKET

