#include "csocket.h"

#include <string.h>
#include <stdlib.h>

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


int    CSocket::Connect(const char *host, const char* port)
{

    m_socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socketFd < 0) {
        return -1;
    }

    m_address.ipv4.sin_addr.s_addr = inet_addr(getIPByName(host));
    m_address.ipv4.sin_family = AF_INET;
    m_address.ipv4.sin_port = htons((uint16_t) atoi(port));

    if (connect(m_socketFd, (struct sockaddr*)&m_address.ipv4,
                sizeof(m_address.ipv4)) < 0 ) {
        return -1;
    }

    return 0;
}

int CSocket::Send(const char *msg)
{
    if (send(m_socketFd, msg, strlen(msg), 0) < 0) {
        return -1;
    }

    return 0;
}


int CSocket::Recieve()
{
    char buff[3000] = {0};

    int res = 0;
    if (recv(m_socketFd, buff, sizeof(buff), 0) < 0) {
        return -1;
    }
    // this is test - remove it later!!!
    puts(buff);

}


int CSocket::Bind(uint16_t port)
{
    struct sockaddr_in client;
    int new_socket, c;
    m_address.ipv4.sin_family = AF_INET;
    m_address.ipv4.sin_addr.s_addr = INADDR_ANY;
    m_address.ipv4.sin_port = htons(port);

    if (bind(m_socketFd, (struct sockaddr*)&m_address.ipv4,
             sizeof(m_address.ipv4)) < 0) {
        return -1;
    }

    listen(m_socketFd, 3);

    c = sizeof(struct sockaddr_in);
    new_socket = accept(m_socketFd, (struct sockaddr*)&client,
                        (socklen_t*)&c);
    if (new_socket < 0) {
        return -1;
    }

    puts("Connection accepted");
    return 0;
}

