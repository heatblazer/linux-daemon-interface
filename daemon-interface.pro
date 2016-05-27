QT += core
QT += network


CONFIG += c++11
CONFIG += console



DEFINES += USE_QT_SOCKETS

TARGET = test_daemon

SOURCES += main.cpp \
    daemon-interface.cpp \
    test-signals.cpp \
    defs.cpp \
    signals-interface.cpp \
    watchdog.cpp \
    schedulers.cpp \
    network/qtsocket.cpp \
    network/csocket.cpp \
    async/cthread.cpp \
    network/msg.cpp

HEADERS += \
    daemon-inerface.h \
    signals-interface.h \
    defs.h \
    test-signals.h \
    watchdog.h \
    schedulers.h \
    network/qtsocket.h \
    network/csocket.h \
    async/cthread.h \
    network/msg.h


#for threads
LIBS += -lpthread

#for C sockets
LIBS += -lresolv

#for rpc
LIBS += -lnsl


