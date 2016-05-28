#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/fcntl.h>

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <pthread.h>
#include <time.h> //sleep
#include "signals-interface.h"
#include "daemon-inerface.h"
#include "defs.h"

/// statics
static void fiforeader(void)
{

    FILE* fp = fopen("log.txt", "a+");
    if ( !fp ) {
        exit(1);
    }

    static char *fifoname = "fifofile";
    int num, fd;
    mknod(fifoname, S_IFIFO | 0666, 0);
    char s[300];
    fd = open(fifoname, O_RDONLY);

    if  ( (num = read(fd, s, 300)) != -1 ) {
        s[num]=0;
        fprintf(fp, "\n%s", s);
    }
    //fixed bug with not closing the fptr
    fclose(fp);

}

///

Daemon::Daemon()
{
    //use the default signal handler if none
    //it`s better to have your own implementation of the
    //signal handler function

}

Daemon::~Daemon()
{
    //mrbitmap:
    //finish all tasks or join all threads if any
}

void Daemon::myFork()
{
    m_pid = fork(); //get owner of the process;
    if ( m_pid <  0 ){
        exit(EXIT_FAILURE);
    }
    if ( m_pid > 0 ) {
        exit(EXIT_SUCCESS);
    }
}

//the time to sleep and the function to set it
unsigned int Daemon::m_sleepSeconds = 1;
void Daemon::set_sleep_time(unsigned int stime)
{
    m_sleepSeconds = stime;
}



//the starting function - EXPERIMENTAL!!!
int Daemon::start(int argc, char** argv)
{
    //test interface
    (void) argc;
    (void) argv;

    myFork();

    m_sessionId = setsid();
    if ( m_sessionId < 0 )
    {
        fprintf(stderr, "Failed in setsid(): %d\n",
                m_sessionId);
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    time_t startTime ;
    time_t endTime ;
    startTime =  endTime = time(NULL);

    myFork();

    task* ring = NULL;


    do {
        // rotate the buffer
        ring = m_tasks_head;
        while ( ring != NULL )
        {
            if ( ring->pTask ){
                ring->pTask(ring->argc, ring->pArgs);
            }
            ring = ring->next;
        }
        ring = m_tasks_head;

   } while ( 1 );


   return 0; //the return 1
}

void  Daemon::registerTask(int ID, int (*work)(int, void*), int argc, void *pArg)
{
    task* ntask = (task*)malloc(sizeof(task));
    ntask->taskId = ID;

    ntask->argc = argc;
    ntask->pArgs  = pArg;
    ntask->pTask = work;

    ntask->next = m_tasks_head;
    m_tasks_head = ntask;

}


void Daemon::deregisterTask(int ID)
{
    (void) ID;
}
