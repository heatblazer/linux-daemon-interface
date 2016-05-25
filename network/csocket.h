#ifndef CSOCKET
#define CSOCKET

#include "defs.h"

class CSocket
{
public:
    CSocket();
    virtual ~CSocket();

    virtual void*   get_in_address(struct sockaddr* addr);
    virtual int     Connect(const char* host, const char *port);
    virtual int     Send(const char* msg);
    virtual int     Recieve(void);
    virtual int     Bind(uint16_t port);


private:
    char*   getIPByName(const char* host);

protected:
private:

    int     m_socketFd;
    union {
        sockaddr_in     ipv4;
        sockaddr_in6    ipv6;
    } m_address;



};


#endif // CSOCKET

