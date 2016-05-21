#include "socket.h"

// ANSI C
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Socket::Socket() {}


Socket::~Socket() {}

//! main-like function for initial test
//! \brief Socket::test_main
//! \param argc
//! \param argv
//! \return
//!
int Socket::test_main(int argc, char **argv)
{
    struct addrinfo hints, *res, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN]={0};

    if (argc != 2) {
        fprintf(stderr, "usage: show <hostname>\n");
        return 1;
    }

    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 2;
    }


    printf("IP Addresses for %s\n\n", argv[1]);
    for(p=res; p != NULL; p = p->ai_next) {
        void* addr;
        char* ipver;

        if (p->ai_family == AF_INET) {
            struct sockaddr_in* ipv4 = (struct sockaddr_in*) p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else {
            struct sockaddr_in6* ipv6 = (struct sockaddr_in6*) p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
        printf("%s: %s\n", ipver, ipstr);
    }

    freeaddrinfo(res); // free the list
    return 0;
}
