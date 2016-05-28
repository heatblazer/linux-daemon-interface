#include "qt-daemon.h"

#include "defs.h"


QtDaemon::QtDaemon(QObject *parent)
    :QObject(parent)
{
    // create the QtDaemon

}


QtDaemon::~QtDaemon()
{
    // destroy the daemon if needed to be
}


// the signals handler

void QtDaemon::onSigStkFlt(int sig)
{
    (void) sig;
    exit(0);
}

void QtDaemon::onSigAbrt(int sig)
{
    (void) sig;
    exit(0);
}
void QtDaemon::onSigAlarm(int sig)
{
    (void) sig;
    exit(0);
}
void QtDaemon::onSigBus(int sig)
{
    (void) sig;
    exit(0);
}

void QtDaemon::onSigChld(int sig)
{
    (void) sig;
    exit(0);
}
void QtDaemon::onSigCont(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigFpe(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigHup(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigIll(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigInt(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigIO(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigKill(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigPipe(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigPoll(int sig)
{
    (void) sig;
    exit(0);
}

void QtDaemon::onSigPorf(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigPwr(int sig) {
    (void) sig;
    exit(0);
}

void QtDaemon::onSigQuit(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigSegV(int sig) {
    (void) sig;
    exit(0);
}

void QtDaemon::onSigStop(int sig) {
    (void) sig;
    exit(0);
}

void QtDaemon::onSigSys(int sig) {
    (void) sig;
    exit(0);
}

void QtDaemon::onSigTerm(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigTrap(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigTstp(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigTtIn(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigTtOut(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigUrg(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigUsr1(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigUsr2(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigVtAlarm(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigWinch(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigXCpu(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigXFSZ(int sig){
    (void) sig;
    exit(0);
}


#if 0
void Signals::init(QtDaemon* pDaemon)
{

    if (pDaemon) {
    signal(SIGHUP, onSigHup);			/* Hangup (POSIX).  */
    signal(SIGINT, onSigInt);
    signal(SIGQUIT, onSigQuit);		/* Quit (POSIX).  */
    signal(SIGILL, onSigIll);		/* Illegal instruction (ANSI).  */
    signal(SIGTRAP, onSigTrap);		/* Trace trap (POSIX).  */
    signal(SIGABRT, onSigAbrt);		/* Abort (ANSI).  */
    //signal(SIGIOT, onSigIO);	/* IOT trap (4.2 BSD).  */
    signal(SIGBUS, onSigBus);	/* BUS error (4.2 BSD).  */
    signal(SIGFPE, onSigFpe);	/* Floating-point exception (ANSI).  */
    signal(SIGKILL, onSigKill);	/* Kill, unblockable (POSIX).  */
    signal(SIGUSR1, onSigUsr1);		/* User-defined signal 1 (POSIX).  */
    signal(SIGSEGV, onSigSegV);	/* Segmentation violation (ANSI).  */
    signal(SIGUSR2, onSigUsr2);	/* User-defined signal 2 (POSIX).  */
    signal(SIGPIPE, onSigPipe);	/* Broken pipe (POSIX).  */
    signal(SIGALRM, onSigAlarm);	/* Alarm clock (POSIX).  */
    signal(SIGTERM, onSigTerm);	/* Termination (ANSI).  */
    signal(SIGSTKFLT, onSigStkFlt);	/* Stack fault.  */
    signal(SIGCLD, onSigChld);	/* Same as SIGCHLD (System V).  */
    signal(SIGCHLD, onSigChld);		/* Child status has changed (POSIX).  */
    signal(SIGCONT, onSigCont);		/* Continue (POSIX).  */
    signal(SIGSTOP, onSigStop);			/* Stop, unblockable (POSIX).  */
    signal(SIGTSTP, onSigTstp);		/* Keyboard stop (POSIX).  */
    signal(SIGTTIN, onSigTtIn);		/* Background read from tty (POSIX).  */
    signal(SIGTTOU, onSigTtOut);		/* Background write to tty (POSIX).  */
    signal(SIGURG, onSigUrg);		/* Urgent condition on socket (4.2 BSD).  */
    signal(SIGXCPU, onSigXCpu);		/* CPU limit exceeded (4.2 BSD).  */
    signal(SIGXFSZ, onSigXFSZ);		/* File size limit exceeded (4.2 BSD).  */
    signal(SIGVTALRM, onSigVtAlarm);		/* Virtual alarm clock (4.2 BSD).  */
    signal(SIGWINCH, onSigWinch);		/* Window size change (4.3 BSD, Sun).  */
    signal(SIGPOLL, onSigPoll);			/* Pollable event occurred (System V).  */
    signal(SIGIO, onSigIO);			/* I/O now possible (4.2 BSD).  */
    signal(SIGPWR, onSigPwr);			/* Power failure restart (System V).  */
    signal(SIGSYS, onSigSys);/* Bad system call.  */
    }

}
#endif
