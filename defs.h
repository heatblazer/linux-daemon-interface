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


#ifdef _MSC_VER
# include <intrin.h>
# define CAS(ptr, oldval, newval) \
    _InterlockedCompareExchange(ptr, newval, oldval)
#elif __GNUC__
# if __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 1)
#  error "requires GCC 4.1 or greater"
# endif
# define CAS(ptr, oldval, newval) \
    __sync_val_compare_and_swap(ptr, oldval, newval)
#else
# error "CAS not supported on this platform"
#endif


//the maximum threads that can be spawned
#define MAX_NUM_THREADS 1024

//access m element from struct st
#define MYOFFSETOF(st, m) ( (size_t) &(((st*)0)->m))

//find if element is conained in the struct or member
#define MYCONTAINER_OF(ptr, type, member) (type*) ((char*) (1 ? (ptr) : &((type*)0)->member) - MYOFFSETOF(type, member))




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

