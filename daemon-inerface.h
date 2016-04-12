#ifndef DAEMONINERFACE
#define DAEMONINERFACE
#include "defs.h"

#include "test-signals.h"

class Daemon
{
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

