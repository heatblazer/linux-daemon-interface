#ifndef QTDAEMON_H
#define QTDAEMON_H

// QObject
#include <QtCore>

#include "signals-interface.h"

// defs
#include "defs.h"

enum UxSignals {
SHup	= SIGHUP,		/* Hangup (POSIX).  */
Sint	= SIGINT,		/* Interrupt (ANSI).  */
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

class QtDaemon : public QObject, public SignalsInterface
{
    Q_OBJECT

public:
    explicit QtDaemon(QObject* parent=0);
    ~QtDaemon();

signals:
    void onStateChange(UxSignals sig);

public slots:
    void onSigAbrt(int sig);
    void onSigAlarm(int sig);
    void onSigBus(int sig);
    void onSigChld(int sig);
    void onSigCont(int sig);
    void onSigFpe(int sig);
    void onSigHup(int sig);
    void onSigIll(int sig);
    void onSigInt(int sig);
    void onSigIO(int sig);
    void onSigKill(int sig);
    void onSigPipe(int sig);
    void onSigPoll(int sig);
    void onSigPorf(int sig);
    void onSigPwr(int sig) ;
    void onSigQuit(int sig);
    void onSigSegV(int sig) ;
    void onSigStkFlt(int sig);
    void onSigStop(int sig);
    void onSigSys(int sig) ;
    void onSigTerm(int sig);
    void onSigTrap(int sig);
    void onSigTstp(int sig);
    void onSigTtIn(int sig);
    void onSigTtOut(int sig);
    void onSigUrg(int sig);
    void onSigUsr1(int sig);
    void onSigUsr2(int sig);
    void onSigVtAlarm(int sig);
    void onSigWinch(int sig);
    void onSigXCpu(int sig);
    void onSigXFSZ(int sig);

};



#endif // QTDAEMON_H
