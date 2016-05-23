#ifndef CSOCKET
#define CSOCKET

#include "defs.h"

class CSocket
{
public:
    CSocket();
    virtual ~CSocket();

    virtual void*   get_in_address(struct sockaddr* addr);
    virtual int     connect(const char* host, const char *port);


private:
    char*   getIPByName(const char* host);

protected:
private:



};


#endif // CSOCKET

