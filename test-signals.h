#pragma once

#include "signals-interface.h"


class TestInterface : public SignalsInterface
{
public:
   TestInterface();
   ~TestInterface();

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

class TestSignals
{
// you have to implement your signals
public:
   static SignalsInterface* m_sigInterface;

private: //you don`t bother with the signal handling

   static void onSigHup(int sig) ;

   //SIGINT
   static void onSigInt(int sig) ;

   //SIGQUIT
   static void onSigQuit(int sig) ;

   //SIGILL
   static void onSigIll(int sig) ;

   //SIGTRAP
   static void onSigTrap(int sig) ;

   //SIGABRT
   static void onSigAbrt(int sig) ;

   //SIGBUS
   static void onSigBus(int sig) ;

   //SIGFPE
   static void onSigFpe(int sig) ;

   //SIGKILL
   static void onSigKill(int sig) ;

   //SIGUSR1
   static void onSigUsr1(int sig) ;

   //SIGSEGV
   static void onSigSegV(int sig) ;

   //SIGUSR2
   static void onSigUsr2(int sig)  ;

   //SIGPIPE
   static void onSigPipe(int sig) ;

   //SIGALARM
   static void onSigAlarm(int sig) ;

   //SIGTERM
   static void onSigTerm(int sig) ;

   //SIGCHLD
   static void onSigChld(int sig) ;

   //SIGCONT
   static void onSigCont(int sig) ;

   //SIGSTOP
   static void onSigStop(int sig) ;

   //SIGTSTP
   static void onSigTstp(int sig) ;

   //SIGTTIN
   static void onSigTtIn(int sig) ;

   //SIGTTOU
   static void onSigTtOut(int sig) ;

   //SIGURG
   static void onSigUrg(int sig) ;

   //SIGXCPU
   static void onSigXCpu(int sig) ;

   //SIGXFSZ
   static void onSigXFSZ(int sig) ;

   //SIGVTALRM
   static void onSigVtAlarm(int sig) ;

   //SIGPROF
   static void onSigPorf(int sig) ;

   //SIGWINCH
   static void onSigWinch(int sig) ;

   //SIGIO
   static void onSigIO(int sig) ;

   //SIGPWR
   static void onSigPwr(int sig) ;

   //SIGSYS = UNUSED
   static void onSigSys(int sig ) ;

   //SIGSTKFLT
   static void onSigStkFlt(int sig);

   //SIGPOLL
   static void onSigPoll(int sig);

public:
   TestSignals();
   //dtor
   virtual ~TestSignals();

   static void default_signal_handler(int sig);

};


