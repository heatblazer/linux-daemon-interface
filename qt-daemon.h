#ifndef QTDAEMON_H
#define QTDAEMON_H

// QObject
#include <QtCore>
#include <QApplication>

#include "signals-interface.h"

// defs
#include "defs.h"


namespace qtdaemon {

class QtDaemon; // fwd declaration

class QtDaemon : public QObject, public SignalsInterface
{
    Q_OBJECT
private:
    static QtDaemon*    s_instance;
public:
    explicit QtDaemon(QObject* parent=0);
    ~QtDaemon();

    virtual int start(QApplication *app, int argc, char** argv); // reflect the C main
private:
    void _fork(void);

signals:
    void unixStateChanged(UxSignals sig);

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


private slots:
    void handleUnixChange(void);
private:

    UxSignals   m_state; // current unix state

    //SIGHUP
    static void _onSigHup(int sig) ;

    //SIGINT
    static void _onSigInt(int sig) ;

    //SIGQUIT
    static void _onSigQuit(int sig) ;

    //SIGILL
    static void _onSigIll(int sig) ;

    //SIGTRAP
    static void _onSigTrap(int sig) ;

    //SIGABRT
    static void _onSigAbrt(int sig) ;

    //SIGBUS
    static void _onSigBus(int sig) ;

    //SIGFPE
    static void _onSigFpe(int sig) ;

    //SIGKILL
    static void _onSigKill(int sig) ;

    //SIGUSR1
    static void _onSigUsr1(int sig) ;

    //SIGSEGV
    static void _onSigSegV(int sig) ;

    //SIGUSR2
    static void _onSigUsr2(int sig)  ;

    //SIGPIPE
    static void _onSigPipe(int sig) ;

    //SIGALARM
    static void _onSigAlarm(int sig) ;

    //SIGTERM
    static void _onSigTerm(int sig) ;

    //SIGCHLD
    static void _onSigChld(int sig) ;

    //SIGCONT
    static void _onSigCont(int sig) ;

    //SIGSTOP
    static void _onSigStop(int sig) ;

    //SIGTSTP
    static void _onSigTstp(int sig) ;

    //SIGTTIN
    static void _onSigTtIn(int sig) ;

    //SIGTTOU
    static void _onSigTtOut(int sig) ;

    //SIGURG
    static void _onSigUrg(int sig) ;

    //SIGXCPU
    static void _onSigXCpu(int sig) ;

    //SIGXFSZ
    static void _onSigXFSZ(int sig) ;

    //SIGVTALRM
    static void _onSigVtAlarm(int sig) ;

    //SIGPROF
    static void _onSigPorf(int sig) ;

    //SIGWINCH
    static void _onSigWinch(int sig) ;

    //SIGIO
    static void _onSigIO(int sig) ;

    //SIGPWR
    static void _onSigPwr(int sig) ;

    //SIGSYS = UNUSED
    static void _onSigSys(int sig ) ;

    //SIGSTKFLT
    static void _onSigStkFlt(int sig);

    //SIGPOLL
    static void _onSigPoll(int sig);


private:  /// members
    pid_t   m_pid;
    pid_t   m_sessionId;
    bool    isInit;
};

} // namespace qtdaemon

#endif // QTDAEMON_H
