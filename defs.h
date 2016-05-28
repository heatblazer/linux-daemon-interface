#ifndef DEFS
#define DEFS

// unix standarts
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <stddef.h>

// for rpc messageing
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/types.h>

// socket programming
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// custom logger
#include "qtlogger/qtlogger.h"


// msvc atomics operations
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


typedef void (*pSignalHanlder)(int);


// enum unix signals
enum UxSignals {
    SHup	= SIGHUP,		/* Hangup (POSIX).  */
    SInt	= SIGINT,		/* Interrupt (ANSI).  */
    SQuit	= SIGQUIT,		/* Quit (POSIX).  */
    SIll	= SIGILL,		/* Illegal instruction (ANSI).  */
    STrap	= SIGTRAP,		/* Trace trap (POSIX).  */
    SAbrt	= SIGABRT,		/* Abort (ANSI).  */
    SIot	= SIGIOT,		/* IOT trap (4.2 BSD).  */
    SBus	= SIGBUS,		/* BUS error (4.2 BSD).  */
    SFpe	= SIGFPE,		/* Floating-point exception (ANSI).  */
    SKill	= SIGKILL,		/* Kill, unblockable (POSIX).  */
    SUsr1	= SIGUSR1,		/* User-defined signal 1 (POSIX).  */
    SSegv	= SIGSEGV,		/* Segmentation violation (ANSI).  */
    SUsr2	= SIGUSR2,		/* User-defined signal 2 (POSIX).  */
    SPipe	= SIGPIPE,		/* Broken pipe (POSIX).  */
    SAlrm	= SIGALRM,		/* Alarm clock (POSIX).  */
    STerm	= SIGTERM,		/* Termination (ANSI).  */
    SStkFlt	= SIGSTKFLT,	/* Stack fault.  */
    SCld	= SIGCLD,		/* Same as SIGCHLD (System V).  */
    SChld	= SIGCHLD,		/* Child status has changed (POSIX).  */
    SCont	= SIGCONT,		/* Continue (POSIX).  */
    SStop	= SIGSTOP,		/* Stop, unblockable (POSIX).  */
    STstp	= SIGTSTP,		/* Keyboard stop (POSIX).  */
    STtin	= SIGTTIN,		/* Background read from tty (POSIX).  */
    STtou	= SIGTTOU,		/* Background write to tty (POSIX).  */
    SUrg	= SIGURG,		/* Urgent condition on socket (4.2 BSD).  */
    SXCpu	= SIGXCPU,		/* CPU limit exceeded (4.2 BSD).  */
    SXfsz	= SIGXFSZ,		/* File size limit exceeded (4.2 BSD).  */
    SVTAlrm	= SIGVTALRM,	/* Virtual alarm clock (4.2 BSD).  */
    SProf	= SIGPROF,		/* Profiling alarm clock (4.2 BSD).  */
    SWinch	= SIGWINCH,		/* Window size change (4.3 BSD, Sun).  */
    SPoll	= SIGPOLL,		/* Pollable event occurred (System V).  */
    SIO	 = SIGIO,			/* I/O now possible (4.2 BSD).  */
    SPwr	= SIGPWR,		/* Power failure restart (System V).  */
    SSys = SIGSYS,		/* Bad system call.  */
    SUnused = SIGUNUSED

};



#endif // DEFS

