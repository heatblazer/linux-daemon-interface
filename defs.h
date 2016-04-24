#pragma once
#ifndef DEFS
#define DEFS

#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <stddef.h>

//link with libxml2 too
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/types.h>



#define ENTER_CRITICAL_SECTION do { \
    static pthread_mutex_t cs =     PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP; \
    pthread_mutex_lock(&cs);

#define LEAVE_CRITICAL_SECTION \
    pthread_mutex_unlock(&cs); \
    } while ( 0 ) ;


#define LOG_FILE "log.txt"
void writer(const char* msg);
typedef void (*pSignalHanlder)(int);

#endif // DEFS

