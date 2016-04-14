#pragma once
#ifndef DEFS
#define DEFS

#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>

//link with libxml2 too



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

