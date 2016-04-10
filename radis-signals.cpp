#include "radis-signals.h"
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "defs.h"


RadisInterface::RadisInterface()
{ }

RadisInterface::~RadisInterface()
{ }

void RadisInterface::onSigStkFlt(int sig)
{
    (void) sig;
    writer("SIGSTKFLT caught!\n");
    exit(0);
}

void RadisInterface::onSigAbrt(int sig)
{
    (void) sig;
    writer("SIGABRT caught!\n");
    exit(0);
}
void RadisInterface::onSigAlarm(int sig)
{
    (void) sig;
    writer("SIGALRM caught!\n");
    exit(0);
}
void RadisInterface::onSigBus(int sig)
{
    (void) sig;
    writer("SIGBUS caught!\n");
    exit(0);
}
void RadisInterface::onSigChld(int sig)
{
    (void) sig;
    writer("SIGCHLD caught!\n");
    exit(0);
}
void RadisInterface::onSigCont(int sig){
    (void) sig;
    writer("SIGCONT caught!\n");
    exit(0);
}

void RadisInterface::onSigFpe(int sig){
    (void) sig;
    writer("SIGFPE caught!\n");
    exit(0);
}

void RadisInterface::onSigHup(int sig){
    (void) sig;
    writer("SIGHUP caught!\n");
    exit(0);
}

void RadisInterface::onSigIll(int sig){
    (void) sig;
    writer("SIGILL caught!\n");
    exit(0);
}

void RadisInterface::onSigInt(int sig){
    (void) sig;
    writer("SIGINT caught!\n");
    exit(0);
}

void RadisInterface::onSigIO(int sig){
    (void) sig;
    writer("SIGIO caught!\n");
    exit(0);
}

void RadisInterface::onSigKill(int sig){
    (void) sig;
    writer("SIGKILL caught!\n");
    exit(0);
}

void RadisInterface::onSigPipe(int sig){
    (void) sig;
    writer("SIGPIPE caught!\n");
    exit(0);
}

void RadisInterface::onSigPoll(int sig)
{
    (void) sig;
    writer("SIGPOLL caught!\n");
    exit(0);
}

void RadisInterface::onSigPorf(int sig){
    (void) sig;
    writer("SIGPORF caught!\n");
    exit(0);
}

void RadisInterface::onSigPwr(int sig) {
    (void) sig;
    writer("SIGPWR caught!\n");
    exit(0);
}

void RadisInterface::onSigQuit(int sig){
    (void) sig;
    writer("SIGQUIT caught!\n");
    exit(0);
}

void RadisInterface::onSigSegV(int sig) {
    (void) sig;
    writer("SIGSEGV caught!\n");
    exit(0);
}


void RadisInterface::onSigStop(int sig) {
    (void) sig;
    writer("SIGSTOP caught!\n");
    exit(0);
}

void RadisInterface::onSigSys(int sig) {
    (void) sig;
    writer("SIGSYS caught!\n");
    exit(0);
}

void RadisInterface::onSigTerm(int sig){
    (void) sig;
    writer("SIGTERM caught!\n");
    exit(0);
}

void RadisInterface::onSigTrap(int sig){
    (void) sig;
    writer("SIGTRAP caught!\n");
    exit(0);
}

void RadisInterface::onSigTstp(int sig){
    (void) sig;
    writer("SIGTSTP caught!\n");
    exit(0);
}

void RadisInterface::onSigTtIn(int sig){
    (void) sig;
    writer("SIGTTIN caught!\n");
    exit(0);
}

void RadisInterface::onSigTtOut(int sig){
    (void) sig;
    writer("SIGTTOUT caught!\n");
    exit(0);
}

void RadisInterface::onSigUrg(int sig){
    (void) sig;
    writer("SIGURG caught!\n");
    exit(0);
}

void RadisInterface::onSigUsr1(int sig){
    (void) sig;
    writer("SIGUSR1 caught!\n");
    exit(0);
}

void RadisInterface::onSigUsr2(int sig){
    (void) sig;
    writer("SIGUSR2 caught!\n");
    exit(0);
}

void RadisInterface::onSigVtAlarm(int sig){
    (void) sig;
    writer("SIGVTALRM caught!\n");
    exit(0);
}

void RadisInterface::onSigWinch(int sig){
    (void) sig;
    writer("SIGWINCH caught!\n");
    exit(0);
}

void RadisInterface::onSigXCpu(int sig){
    (void) sig;
    writer("SIGXCPU caught!\n");
    exit(0);
}

void RadisInterface::onSigXFSZ(int sig){
    (void) sig;
    writer("SIGXFSZ caught!\n");
    exit(0);
}

SignalsInterface*
    RadisSignals::m_sigInterface = new RadisInterface;

RadisSignals::RadisSignals()
{

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

RadisSignals::~RadisSignals()
{

}


void RadisSignals::default_signal_handler(int sig)
{

}//default signal handler for test

void RadisSignals::onSigAbrt(int sig)
{
    m_sigInterface->onSigAbrt(sig);
}

void RadisSignals::onSigAlarm(int sig)
{
    m_sigInterface->onSigAlarm(sig);
}

void RadisSignals::onSigBus(int sig)
{
    m_sigInterface->onSigBus(sig);
}

void RadisSignals::onSigChld(int sig)
{
    m_sigInterface->onSigChld(sig);
}

void RadisSignals::onSigCont(int sig)
{
    m_sigInterface->onSigCont(sig);
}

void RadisSignals::onSigFpe(int sig)
{
    m_sigInterface->onSigFpe(sig);
}

void RadisSignals::onSigHup(int sig)
{
    m_sigInterface->onSigHup(sig);
}

void RadisSignals::onSigIll(int sig)
{
    m_sigInterface->onSigIll(sig);
}

void RadisSignals::onSigInt(int sig)
{
    m_sigInterface->onSigInt(sig);
}

void RadisSignals::onSigIO(int sig)
{
    m_sigInterface->onSigIO(sig);
}

void RadisSignals::onSigKill(int sig)
{
    m_sigInterface->onSigKill(sig);
}

void RadisSignals::onSigPipe(int sig)
{
    m_sigInterface->onSigPipe(sig);
}

void RadisSignals::onSigPorf(int sig)
{
    m_sigInterface->onSigPorf(sig);
}

void RadisSignals::onSigPwr(int sig)
{
    m_sigInterface->onSigPwr(sig);
}

void RadisSignals::onSigQuit(int sig)
{
    m_sigInterface->onSigQuit(sig);
}

void RadisSignals::onSigSegV(int sig)
{
    m_sigInterface->onSigSegV(sig);
}

void RadisSignals::onSigStop(int sig)
{
    m_sigInterface->onSigStop(sig);
}

void RadisSignals::onSigSys(int sig)
{
    m_sigInterface->onSigSys(sig);
}

void RadisSignals::onSigTerm(int sig)
{
    m_sigInterface->onSigTerm(sig);
}

void RadisSignals::onSigTrap(int sig)
{
    m_sigInterface->onSigTrap(sig);
}

void RadisSignals::onSigTstp(int sig)
{
    m_sigInterface->onSigTstp(sig);
}

void RadisSignals::onSigTtIn(int sig)
{
    m_sigInterface->onSigTtIn(sig);
}

void RadisSignals::onSigTtOut(int sig)
{
    m_sigInterface->onSigTtOut(sig);
}

void RadisSignals::onSigUrg(int sig)
{
    m_sigInterface->onSigUrg(sig);
}

void RadisSignals::onSigUsr1(int sig)
{
    m_sigInterface->onSigUsr1(sig);
}

void RadisSignals::onSigUsr2(int sig)
{
    m_sigInterface->onSigUsr2(sig);
}

void RadisSignals::onSigVtAlarm(int sig)
{
    m_sigInterface->onSigVtAlarm(sig);
}

void RadisSignals::onSigWinch(int sig)
{
    m_sigInterface->onSigWinch(sig);
}

void RadisSignals::onSigXCpu(int sig)
{
    m_sigInterface->onSigXCpu(sig);
}

void RadisSignals::onSigXFSZ(int sig)
{
    m_sigInterface->onSigXFSZ(sig);
}


void RadisSignals::onSigStkFlt(int sig)
{
    m_sigInterface->onSigStkFlt(sig);
}

void RadisSignals::onSigPoll(int sig)
{
    m_sigInterface->onSigPoll(sig);
}


