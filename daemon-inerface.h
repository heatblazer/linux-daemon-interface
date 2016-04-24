#ifndef DAEMONINERFACE
#define DAEMONINERFACE
#include "defs.h"
#include "test-signals.h"
#include <stdlib.h>

#ifdef MAX_TASKS
#   undef MAX_TASKS
#   define MAX_TASKS 4
#else
#   define MAX_TASKS 4
#endif


#define SHELL "/bin/sh"
class Daemon
{
public:

    static int System(const char* cmd)
    {
        int status = 0;
        pid_t pid = fork();
        if ( pid == 0 ) {
            execl(SHELL, SHELL, "-c", cmd, NULL);
            _exit(EXIT_FAILURE);
        } else if ( pid < 0 ) {
           status = -1;
        } else {
            if ( waitpid(pid, &status, 0) != pid )
            {
                status = -1;
            }
            return status;
        }

    }

private:
    //a stack based task list
    typedef struct _task {
        int taskId;
        int argc;
        void* pArgs;
        int (*pTask)(int, void*);
        struct _task* next;
    } task;

    task*       m_tasks;

    ///for IPC tasks
    struct
    {
        long mtype;
        struct {
            char task_name[200];
            int argc;
            void* pArgs;
            int ( *pfoo)(int, void*);
        } work;
    } msg_task;

private:

    pid_t m_pid;
    pid_t m_sessionId;
    static unsigned int m_sleepSeconds;

    TestSignals m_signals;

    //this struct will be used for more advanced programs
    //with sigaction(...)
    struct {
        struct sigaction signal_action;
        void (*special_hanlde)(int sig, siginfo_t* sinfo, void* context);
    } m_actions[31]; //maximum signals

private:
    //simple for/exit procedure
    void    myFork(void);

public:
    //setup new and old actions



    Daemon(); //default ctor for test
    virtual ~Daemon(); //if we need derivates

    //simple writer
    static void writer(const char* msg);

    static void set_sleep_time(unsigned int stime);

    virtual int start(int argc, char** argv);
    virtual void registerTask(int ID, int (*work)(int, void*), int argc, void *pArg );
    virtual void deregisterTask(int ID);

};

#endif // DAEMONINERFACE

