#include "csocket.h"

// ANSI C
#include <string.h>
#include <stdlib.h>


bool CSocket::m_isRunning = true;

CSocket::CSocket()
{

}


CSocket::~CSocket()
{

}


void*   CSocket::get_in_address(struct sockaddr *addr)
{
    if (addr->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)addr)->sin_addr);
    } else {
        return &(((struct sockaddr_in6*)addr)->sin6_addr);
    }
}


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


void*    CSocket::run(void *pdata)
{
    CSocket* s = (CSocket*) pdata;
    while (CSocket::m_isRunning) {
        // test
        s->Send("Action: Ping\r\n\r\n");
        s->Recieve();
    }

}


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
    m_thread.init(256 * 1024, CSocket::run, this);
    m_thread.join();


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

int CSocket::Send(const char *msg)
{
    if (send(m_socketFd, msg, strlen(msg), 0) < 0) {
        return -1;
    }

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
    return 0;
}




