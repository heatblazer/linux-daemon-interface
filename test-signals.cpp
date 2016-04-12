#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-signals.h"
#include "defs.h"


TestInterface::TestInterface()
{ }

TestInterface::~TestInterface()
{ }

void TestInterface::onSigStkFlt(int sig)
{
    (void) sig;
    writer("SIGSTKFLT caught!\n");
    exit(0);
}

void TestInterface::onSigAbrt(int sig)
{
    (void) sig;
    writer("SIGABRT caught!\n");
    exit(0);
}
void TestInterface::onSigAlarm(int sig)
{
    (void) sig;
    writer("SIGALRM caught!\n");
    exit(0);
}
void TestInterface::onSigBus(int sig)
{
    (void) sig;
    writer("SIGBUS caught!\n");
    exit(0);
}
void TestInterface::onSigChld(int sig)
{
    (void) sig;
    writer("SIGCHLD caught!\n");
    exit(0);
}
void TestInterface::onSigCont(int sig){
    (void) sig;
    writer("SIGCONT caught!\n");
    exit(0);
}

void TestInterface::onSigFpe(int sig){
    (void) sig;
    writer("SIGFPE caught!\n");
    exit(0);
}

void TestInterface::onSigHup(int sig){
    (void) sig;
    writer("SIGHUP caught!\n");
    exit(0);
}

void TestInterface::onSigIll(int sig){
    (void) sig;
    writer("SIGILL caught!\n");
    exit(0);
}

void TestInterface::onSigInt(int sig){
    (void) sig;
    writer("SIGINT caught!\n");
    exit(0);
}

void TestInterface::onSigIO(int sig){
    (void) sig;
    writer("SIGIO caught!\n");
    exit(0);
}

void TestInterface::onSigKill(int sig){
    (void) sig;
    writer("SIGKILL caught!\n");
    exit(0);
}

void TestInterface::onSigPipe(int sig){
    (void) sig;
    writer("SIGPIPE caught!\n");
    exit(0);
}

void TestInterface::onSigPoll(int sig)
{
    (void) sig;
    writer("SIGPOLL caught!\n");
    exit(0);
}

void TestInterface::onSigPorf(int sig){
    (void) sig;
    writer("SIGPORF caught!\n");
    exit(0);
}

void TestInterface::onSigPwr(int sig) {
    (void) sig;
    writer("SIGPWR caught!\n");
    exit(0);
}

void TestInterface::onSigQuit(int sig){
    (void) sig;
    writer("SIGQUIT caught!\n");
    exit(0);
}

void TestInterface::onSigSegV(int sig) {
    (void) sig;
    writer("SIGSEGV caught!\n");
    exit(0);
}


void TestInterface::onSigStop(int sig) {
    (void) sig;
    writer("SIGSTOP caught!\n");
    exit(0);
}

void TestInterface::onSigSys(int sig) {
    (void) sig;
    writer("SIGSYS caught!\n");
    exit(0);
}

void TestInterface::onSigTerm(int sig){
    (void) sig;
    writer("SIGTERM caught!\n");
    exit(0);
}

void TestInterface::onSigTrap(int sig){
    (void) sig;
    writer("SIGTRAP caught!\n");
    exit(0);
}

void TestInterface::onSigTstp(int sig){
    (void) sig;
    writer("SIGTSTP caught!\n");
    exit(0);
}

void TestInterface::onSigTtIn(int sig){
    (void) sig;
    writer("SIGTTIN caught!\n");
    exit(0);
}

void TestInterface::onSigTtOut(int sig){
    (void) sig;
    writer("SIGTTOUT caught!\n");
    exit(0);
}

void TestInterface::onSigUrg(int sig){
    (void) sig;
    writer("SIGURG caught!\n");
    exit(0);
}

void TestInterface::onSigUsr1(int sig){
    (void) sig;
    writer("SIGUSR1 caught!\n");
    exit(0);
}

void TestInterface::onSigUsr2(int sig){
    (void) sig;
    writer("SIGUSR2 caught!\n");
    exit(0);
}

void TestInterface::onSigVtAlarm(int sig){
    (void) sig;
    writer("SIGVTALRM caught!\n");
    exit(0);
}

void TestInterface::onSigWinch(int sig){
    (void) sig;
    writer("SIGWINCH caught!\n");
    exit(0);
}

void TestInterface::onSigXCpu(int sig){
    (void) sig;
    writer("SIGXCPU caught!\n");
    exit(0);
}

void TestInterface::onSigXFSZ(int sig){
    (void) sig;
    writer("SIGXFSZ caught!\n");
    exit(0);
}

SignalsInterface*
    TestSignals::m_sigInterface = new TestInterface;

TestSignals::TestSignals()
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

TestSignals::~TestSignals()
{

}


void TestSignals::default_signal_handler(int sig)
{

}//default signal handler for test

void TestSignals::onSigAbrt(int sig)
{
    m_sigInterface->onSigAbrt(sig);
}

void TestSignals::onSigAlarm(int sig)
{
    m_sigInterface->onSigAlarm(sig);
}

void TestSignals::onSigBus(int sig)
{
    m_sigInterface->onSigBus(sig);
}

void TestSignals::onSigChld(int sig)
{
    m_sigInterface->onSigChld(sig);
}

void TestSignals::onSigCont(int sig)
{
    m_sigInterface->onSigCont(sig);
}

void TestSignals::onSigFpe(int sig)
{
    m_sigInterface->onSigFpe(sig);
}

void TestSignals::onSigHup(int sig)
{
    m_sigInterface->onSigHup(sig);
}

void TestSignals::onSigIll(int sig)
{
    m_sigInterface->onSigIll(sig);
}

void TestSignals::onSigInt(int sig)
{
    m_sigInterface->onSigInt(sig);
}

void TestSignals::onSigIO(int sig)
{
    m_sigInterface->onSigIO(sig);
}

void TestSignals::onSigKill(int sig)
{
    m_sigInterface->onSigKill(sig);
}

void TestSignals::onSigPipe(int sig)
{
    m_sigInterface->onSigPipe(sig);
}

void TestSignals::onSigPorf(int sig)
{
    m_sigInterface->onSigPorf(sig);
}

void TestSignals::onSigPwr(int sig)
{
    m_sigInterface->onSigPwr(sig);
}

void TestSignals::onSigQuit(int sig)
{
    m_sigInterface->onSigQuit(sig);
}

void TestSignals::onSigSegV(int sig)
{
    m_sigInterface->onSigSegV(sig);
}

void TestSignals::onSigStop(int sig)
{
    m_sigInterface->onSigStop(sig);
}

void TestSignals::onSigSys(int sig)
{
    m_sigInterface->onSigSys(sig);
}

void TestSignals::onSigTerm(int sig)
{
    m_sigInterface->onSigTerm(sig);
}

void TestSignals::onSigTrap(int sig)
{
    m_sigInterface->onSigTrap(sig);
}

void TestSignals::onSigTstp(int sig)
{
    m_sigInterface->onSigTstp(sig);
}

void TestSignals::onSigTtIn(int sig)
{
    m_sigInterface->onSigTtIn(sig);
}

void TestSignals::onSigTtOut(int sig)
{
    m_sigInterface->onSigTtOut(sig);
}

void TestSignals::onSigUrg(int sig)
{
    m_sigInterface->onSigUrg(sig);
}

void TestSignals::onSigUsr1(int sig)
{
    m_sigInterface->onSigUsr1(sig);
}

void TestSignals::onSigUsr2(int sig)
{
    m_sigInterface->onSigUsr2(sig);
}

void TestSignals::onSigVtAlarm(int sig)
{
    m_sigInterface->onSigVtAlarm(sig);
}

void TestSignals::onSigWinch(int sig)
{
    m_sigInterface->onSigWinch(sig);
}

void TestSignals::onSigXCpu(int sig)
{
    m_sigInterface->onSigXCpu(sig);
}

void TestSignals::onSigXFSZ(int sig)
{
    m_sigInterface->onSigXFSZ(sig);
}


void TestSignals::onSigStkFlt(int sig)
{
    m_sigInterface->onSigStkFlt(sig);
}

void TestSignals::onSigPoll(int sig)
{
    m_sigInterface->onSigPoll(sig);
}


