#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/fcntl.h>

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <time.h> //sleep
#include "signals-interface.h"
#include "daemon-inerface.h"
#include "defs.h"


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

    myFork();

    m_sessionId = setsid();
    if ( m_sessionId < 0 )
    {
        fprintf(stderr, "Failed in setsid(): %d\n",
                m_sessionId);
        exit(EXIT_FAILURE);
    }

    myFork();

    umask(0);
    chdir(argv[1]);


    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    time_t startTime ;
    time_t endTime ;
    startTime =  endTime = time(NULL);
    do {

        //daemon task iterface goes here
        //todo a class for specific tasks


        sleep(m_sleepSeconds);

   } while ( 1 );

   return 1; //the return 1
}

