#ifndef DAEMONINERFACE
#define DAEMONINERFACE
#include "defs.h"


#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include "radis-signals.h"

class Daemon
{
private:

    pid_t m_pid;
    pid_t m_sessionId;
    static unsigned int m_sleepSeconds;

    RadisSignals m_signals;

private:
    void    myFork(void);

public:

    Daemon(); //default ctor for test
    virtual ~Daemon(); //if we need derivates
    //simple writer
    static void writer(const char* msg);
    static void set_sleep_time(unsigned int stime);
    virtual int start(int argc, char** argv);

};

#endif // DAEMONINERFACE

