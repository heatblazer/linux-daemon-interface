#ifndef QTDAEMON_H
#define QTDAEMON_H

// QObject
#include <QtCore>

#include "signals-interface.h"

// defs
#include "defs.h"


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
