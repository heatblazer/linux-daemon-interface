#include "csocket.h"

// ANSI C
#include <string.h>
#include <stdlib.h>


bool CSocket::m_isRunning = true;
int CSocket::m_sockets[CSocket::ClienServer::MAX]={0};

CSocket::CSocket() : p_head(0)
{
    m_thread.init(1024 * 1024, CSocket::run, this, 10, false);
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

    m_sockets[ClienServer::CLIENT] = socket(AF_INET, SOCK_STREAM, 0);
    if (m_sockets[ClienServer::CLIENT] < 0) {
        return -1;
    }

    m_address[ClienServer::CLIENT].ipv4.sin_addr.s_addr = inet_addr(host);
    m_address[ClienServer::CLIENT].ipv4.sin_family = AF_INET;
    m_address[ClienServer::CLIENT].ipv4.sin_port = htons((uint16_t) atoi(port));

    if (connect(m_sockets[ClienServer::CLIENT],
                (struct sockaddr*)&m_address[ClienServer::CLIENT].ipv4,
                sizeof(m_address[ClienServer::CLIENT].ipv4)) < 0 ) {
        return -1;
    }


    // move the threads elsewhere, since we`ll stick here
    // before we got loged in
    //             stack size, runnable,   usrdata, priority //
    m_thread.init(1024 * 1024, CSocket::run, this, 10, false);

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


}


//! The function to be pushed on the call stack
//! \brief CSocket::_privateSend
//! \param msg
//! \return
//!
int CSocket::_privateSend(const char *msg)
{
    ENTER_CRITICAL_SECTION
    if (send(m_sockets[ClienServer::CLIENT], msg, strlen(msg), 0) < 0) {
        return -1;
    }
    LEAVE_CRITICAL_SECTION
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
    ENTER_CRITICAL_SECTION
    char buff[3000] = {0};

    if (recv(m_sockets[ClienServer::CLIENT], buff, sizeof(buff), 0) < 0) {
        return -1;
    }
    // this is test - remove it later!!!
    puts(buff);
    puts("\n");
    LEAVE_CRITICAL_SECTION
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
            p_head = 0;
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
    // omit for now
    CSocket *psck = (CSocket*)pdata;

    struct sockaddr_in si_me, si_other;
    int s, i, slen=sizeof(si_me), recv_len;
    char buff[1024]={0}; // one shot zerofill
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("socket");
        exit(1);
    }

    memset((char*)&si_me, 0, sizeof(si_me));

    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(8888);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(s, (struct sockaddr*)&si_me, sizeof(si_me)) < 0) {
        perror("bind");
        exit(1);
    }


    while (CSocket::m_isRunning)
    {
        FILE* fp = fopen("servlog.log", "a");
        if(!fp) {
            // handle err
        }
        fprintf(fp, "Waiting data:");

        if ((recv_len = recvfrom(s, buff, 1024, 0,
                                 (struct sockaddr*)&si_other,
                                 (socklen_t*)&slen)) < 0)
        {
            perror("recvfrom");
            exit(1);
        }

        fprintf(fp, "Recv packs from: %s:%d\n", inet_ntoa(si_other.sin_addr),
                ntohs(si_other.sin_port));

        fprintf(fp, "Data: %s\n", buff);

        if(sendto(s, buff, recv_len, 0, (struct sockaddr*)&si_other, slen) < 0)
        {
            perror("sendto");
            exit(1);
        }
        fclose(fp);
    }
}

// TODO : work out the test
void *CSocket::test_run(void *pdata)
{
#if 0
    struct sockaddr_in si_other;
    int s, i, slen=sizeof(si_other);
    char buff[512]={0};
    char message[512]={0};

    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) <0) {
        die("socket");
    }

    memset((char*)&si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(8888);

    if(inet_aton("127.0.0.1", &si_other.sin_addr) == 0) {
        fprintf(stderr, "inet_aton() falied\n");
        exit(1);
    }


    while(1) {
        printf(">");
        gets(message);

        if(sendto(s, message, strlen(message), 0, (struct sockaddr*)&si_other
                  , slen) == -1) {
            die("sendto()");
        }
        memset(buff, 0, 512);

        if(recvfrom(s, buff, 512, 0, (struct sockaddr*)&si_other, &slen) == -1)
        {
            die("recvfrom()");
        }
        puts(buff);
    }

    close(s);
    return 0;
#endif
}





