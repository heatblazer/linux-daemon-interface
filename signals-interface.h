#ifndef SIGNALSINTERFACE
#define SIGNALSINTERFACE

class SignalsInterface
{
public:

    //this class will associate every signal with an callback to
    //be used by the daemon
    //SIGHUP
    virtual void    onSigHup(int sig) = 0;

    //SIGINT
    virtual void    onSigInt(int sig) = 0;

    //SIGQUIT
    virtual void    onSigQuit(int sig) = 0;

    //SIGILL
    virtual void    onSigIll(int sig) = 0;

    //SIGTRAP
    virtual void    onSigTrap(int sig) = 0;

    //SIGABRT
    virtual void    onSigAbrt(int sig) = 0;

    //SIGBUS
    virtual void    onSigBus(int sig) = 0;

    //SIGFPE
    virtual void    onSigFpe(int sig) = 0;

    //SIGKILL
    virtual void    onSigKill(int sig) = 0;

    //SIGUSR1
    virtual void    onSigUsr1(int sig) = 0;

    //SIGSEGV
    virtual void    onSigSegV(int sig) = 0;

    //SIGUSR2
    virtual void    onSigUsr2(int sig) = 0;

    //SIGPIPE
    virtual void    onSigPipe(int sig) = 0;

    //SIGALARM
    virtual void    onSigAlarm(int sig) = 0;

    //SIGTERM
    virtual void    onSigTerm(int sig) = 0;

    //SIGCHLD
    virtual void    onSigChld(int sig) = 0;

    //SIGCONT
    virtual void    onSigCont(int sig) = 0;

    //SIGSTOP
    virtual void    onSigStop(int sig) = 0;

    //SIGTSTP
    virtual void    onSigTstp(int sig) = 0;

    //SIGTTIN
    virtual void    onSigTtIn(int sig) = 0;

    //SIGTTOU
    virtual void    onSigTtOut(int sig) =0;

    //SIGURG
    virtual void    onSigUrg(int sig) = 0;

    //SIGXCPU
    virtual void    onSigXCpu(int sig) = 0;

    //SIGXFSZ
    virtual void    onSigXFSZ(int sig) = 0;

    //SIGVTALRM
    virtual void    onSigVtAlarm(int sig) = 0;

    //SIGPROF
    virtual void    onSigPorf(int sig) = 0;

    //SIGWINCH
    virtual void    onSigWinch(int sig) = 0;

    //SIGIO
    virtual void    onSigIO(int sig) = 0;

    //SIGPWR
    virtual void    onSigPwr(int sig) = 0;

    //SIGSYS = UNUSED
    virtual void    onSigSys(int sig) = 0;

    //SIGPOLL
    virtual void    onSigPoll(int sig) = 0;

    //SIGSTKFLT
    virtual void    onSigStkFlt(int sig) = 0;

    //dtor
    virtual ~SignalsInterface() = 0;

};

#endif // SIGNALSINTERFACE

