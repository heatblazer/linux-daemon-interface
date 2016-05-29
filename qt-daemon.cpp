#include "qt-daemon.h"

// qt specific
#include <QApplication>

#include "defs.h"

namespace qtdaemon {



QtDaemon*   QtDaemon::s_instance = new QtDaemon;


QtDaemon::QtDaemon(QObject *parent)
    :QObject(parent), isInit(false)
{
    // create the QtDaemon
    signal(SIGHUP, _onSigHup);			/* Hangup (POSIX).  */
    signal(SIGINT, _onSigInt);
    signal(SIGQUIT, _onSigQuit);		/* Quit (POSIX).  */
    signal(SIGILL, _onSigIll);		/* Illegal instruction (ANSI).  */
    signal(SIGTRAP, _onSigTrap);		/* Trace trap (POSIX).  */
    signal(SIGABRT, _onSigAbrt);		/* Abort (ANSI).  */
    //signal(SIGIOT, onSigIO);	/* IOT trap (4.2 BSD).  */
    signal(SIGBUS, _onSigBus);	/* BUS error (4.2 BSD).  */
    signal(SIGFPE, _onSigFpe);	/* Floating-point exception (ANSI).  */
    signal(SIGKILL, _onSigKill);	/* Kill, unblockable (POSIX).  */
    signal(SIGUSR1, _onSigUsr1);		/* User-defined signal 1 (POSIX).  */
    signal(SIGSEGV, _onSigSegV);	/* Segmentation violation (ANSI).  */
    signal(SIGUSR2, _onSigUsr2);	/* User-defined signal 2 (POSIX).  */
    signal(SIGPIPE, _onSigPipe);	/* Broken pipe (POSIX).  */
    signal(SIGALRM, _onSigAlarm);	/* Alarm clock (POSIX).  */
    signal(SIGTERM, _onSigTerm);	/* Termination (ANSI).  */
    signal(SIGSTKFLT, _onSigStkFlt);	/* Stack fault.  */
    signal(SIGCLD, _onSigChld);	/* Same as SIGCHLD (System V).  */
    signal(SIGCHLD, _onSigChld);		/* Child status has changed (POSIX).  */
    signal(SIGCONT, _onSigCont);		/* Continue (POSIX).  */
    signal(SIGSTOP, _onSigStop);			/* Stop, unblockable (POSIX).  */
    signal(SIGTSTP, _onSigTstp);		/* Keyboard stop (POSIX).  */
    signal(SIGTTIN, _onSigTtIn);		/* Background read from tty (POSIX).  */
    signal(SIGTTOU, _onSigTtOut);		/* Background write to tty (POSIX).  */
    signal(SIGURG, _onSigUrg);		/* Urgent condition on socket (4.2 BSD).  */
    signal(SIGXCPU, _onSigXCpu);		/* CPU limit exceeded (4.2 BSD).  */
    signal(SIGXFSZ, _onSigXFSZ);		/* File size limit exceeded (4.2 BSD).  */
    signal(SIGVTALRM, _onSigVtAlarm);		/* Virtual alarm clock (4.2 BSD).  */
    signal(SIGWINCH, _onSigWinch);		/* Window size change (4.3 BSD, Sun).  */
    signal(SIGPOLL, _onSigPoll);			/* Pollable event occurred (System V).  */
    signal(SIGIO, _onSigIO);			/* I/O now possible (4.2 BSD).  */
    signal(SIGPWR, _onSigPwr);			/* Power failure restart (System V).  */
    signal(SIGSYS, _onSigSys);/* Bad system call.  */


    connect(this, SIGNAL(unixStateChanged(UxSignals)),
            this, SLOT(handleUnixChange()));

}


QtDaemon::~QtDaemon()
{
    // destroy the daemon if needed to be
}


// the signals handler

void QtDaemon::onSigStkFlt(int sig)
{
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigAbrt(int sig)
{
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}
void QtDaemon::onSigAlarm(int sig)
{
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}
void QtDaemon::onSigBus(int sig)
{
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigChld(int sig)
{
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}
void QtDaemon::onSigCont(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigFpe(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigHup(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigIll(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigInt(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigIO(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigKill(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigPipe(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigPoll(int sig)
{
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigPorf(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigPwr(int sig) {
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigQuit(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigSegV(int sig) {
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigStop(int sig) {
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigSys(int sig) {
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigTerm(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigTrap(int sig){
    (void) sig;
    exit(0);
}

void QtDaemon::onSigTstp(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigTtIn(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigTtOut(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigUrg(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigUsr1(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigUsr2(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigVtAlarm(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigWinch(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigXCpu(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::onSigXFSZ(int sig){
    m_state = (UxSignals)sig;
    emit unixStateChanged(m_state);
}

void QtDaemon::handleUnixChange(void)
{
    switch(m_state) {

    case UxSignals::SAbrt: // SIot
        MyLogger::log("SigAbort");
        break;
    case UxSignals::SAlrm:
        MyLogger::log("SigAlrm");
        break;
    case UxSignals::SBus:
        break;
    case UxSignals::SChld: // SCld
        break;
    case UxSignals::SCont:
        break;
    case UxSignals::SFpe:
        break;
    case UxSignals::SHup:
        MyLogger::log("SigHup");
        break;
    case UxSignals::SIll:
        break;
    case UxSignals::SInt:
        break;
    case UxSignals::SKill:
        MyLogger::log("SigKill");
        break;
    case UxSignals::SPipe:
        break;
    case UxSignals::SPoll: //SIo
        break;
    case UxSignals::SProf:
        break;
    case UxSignals::SPwr:
        break;
    case UxSignals::SQuit:
        break;
    case UxSignals::SSegv:
        break;
    case UxSignals::SStkFlt:
        break;
    case UxSignals::SStop:
        break;
    case UxSignals::SSys:
        break;
    case UxSignals::STerm:
        MyLogger::log("SigTerm");
        break;
    case UxSignals::STrap:
        break;
    case UxSignals::STstp:
        break;
    case UxSignals::STtin:
        break;
    case UxSignals::STtou:
        break;
    case UxSignals::SUrg:
        break;
    case UxSignals::SUsr1:
        break;
    case UxSignals::SUsr2:
        break;
    case UxSignals::SXCpu:
        break;
    case UxSignals::SXfsz:
        break;

    }
}

// statics functions to call the implemented virtuals
// private statics

void QtDaemon::_onSigAbrt(int sig)
{
    s_instance->onSigAbrt(sig);
}

void QtDaemon::_onSigAlarm(int sig)
{
    s_instance->onSigAlarm(sig);
}

void QtDaemon::_onSigBus(int sig)
{
    s_instance->onSigBus(sig);
}

void QtDaemon::_onSigChld(int sig)
{
    s_instance->onSigChld(sig);
}

void QtDaemon::_onSigCont(int sig)
{
    s_instance->onSigCont(sig);
}

void QtDaemon::_onSigFpe(int sig)
{
    s_instance->onSigFpe(sig);
}

void QtDaemon::_onSigHup(int sig)
{
    s_instance->onSigHup(sig);
}

void QtDaemon::_onSigIll(int sig)
{
    s_instance->onSigIll(sig);
}

void QtDaemon::_onSigInt(int sig)
{
    s_instance->onSigInt(sig);
}

void QtDaemon::_onSigIO(int sig)
{
    s_instance->onSigIO(sig);
}

void QtDaemon::_onSigKill(int sig)
{
    s_instance->onSigKill(sig);
}

void QtDaemon::_onSigPipe(int sig)
{
    s_instance->onSigPipe(sig);
}

void QtDaemon::_onSigPoll(int sig)
{
    s_instance->onSigPoll(sig);
}

void QtDaemon::_onSigPorf(int sig)
{
    s_instance->onSigPorf(sig);
}

void QtDaemon::_onSigPwr(int sig)
{
    s_instance->onSigPwr(sig);
}

void QtDaemon::_onSigQuit(int sig)
{
    s_instance->onSigQuit(sig);
}

void QtDaemon::_onSigSegV(int sig)
{
    s_instance->onSigSegV(sig);
}

void QtDaemon::_onSigStkFlt(int sig)
{
    s_instance->onSigStkFlt(sig);
}

void QtDaemon::_onSigStop(int sig)
{
    s_instance->onSigStop(sig);
}

void QtDaemon::_onSigSys(int sig)
{
    s_instance->onSigSys(sig);
}

void QtDaemon::_onSigTerm(int sig)
{
    s_instance->onSigTerm(sig);
}

void QtDaemon::_onSigTrap(int sig)
{
    s_instance->onSigTrap(sig);
}

void QtDaemon::_onSigTstp(int sig)
{
    s_instance->onSigTstp(sig);
}

void QtDaemon::_onSigTtIn(int sig)
{
    s_instance->onSigTtIn(sig);
}

void QtDaemon::_onSigTtOut(int sig)
{
    s_instance->onSigTtOut(sig);
}

void QtDaemon::_onSigUrg(int sig)
{
    s_instance->onSigUrg(sig);
}

void QtDaemon::_onSigUsr1(int sig)
{
    s_instance->onSigUsr1(sig);
}

void QtDaemon::_onSigUsr2(int sig)
{
    s_instance->onSigUsr2(sig);
}

void QtDaemon::_onSigVtAlarm(int sig)
{
    s_instance->onSigVtAlarm(sig);
}

void QtDaemon::_onSigWinch(int sig)
{
    s_instance->onSigWinch(sig);
}

void QtDaemon::_onSigXCpu(int sig)
{
    s_instance->onSigXCpu(sig);
}

void QtDaemon::_onSigXFSZ(int sig)
{
    s_instance->onSigXFSZ(sig);
}


int QtDaemon::start(QApplication* app, int argc, char **argv)
{
    // one shot daemon only
    if (!isInit) {

        isInit = true;
        _fork();

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

         _fork();
         do {

             sleep(1000);
        } while(app->exec());
    }

    return 0;

}


void QtDaemon::_fork()
{
    m_pid = fork(); //get owner of the process;
    if ( m_pid <  0 ){
        exit(EXIT_FAILURE);
    }
    if ( m_pid > 0 ) {
        exit(EXIT_SUCCESS);
    }
}


} // namespace qtdaemon
