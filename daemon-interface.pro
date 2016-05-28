QT += core
QT += network
QT += gui
QT += widgets

CONFIG += c++11
CONFIG += console



DEFINES += USE_QT_SOCKETS

TARGET = test_daemon

SOURCES += main.cpp \
    daemon-interface.cpp \
    defs.cpp \
    signals-interface.cpp \
    watchdog.cpp \
    schedulers.cpp \
    network/qtsocket.cpp \
    network/csocket.cpp \
    async/cthread.cpp \
    network/msg.cpp \
    jsonrpc/error.cpp \
    jsonrpc/httphelper.cpp \
    jsonrpc/peer.cpp \
    jsonrpc/responsehandler.cpp \
    jsonrpc/tcphelper.cpp \
    jsonrpc/qt-json/json.cpp \
    Example/qjsontest.cpp   \
    qt-daemon.cpp

HEADERS += \
    daemon-inerface.h \
    signals-interface.h \
    defs.h \
    watchdog.h \
    schedulers.h \
    network/qtsocket.h \
    network/csocket.h \
    async/cthread.h \
    network/msg.h \
    jsonrpc/error.h \
    jsonrpc/httphelper.h \
    jsonrpc/peer.h \
    jsonrpc/responsehandler.h \
    jsonrpc/tcphelper.h \
    jsonrpc/qt-json/json.h \
    Example/qjsontest.h \
    qt-daemon.h


#for threads
LIBS += -lpthread

#for C sockets
LIBS += -lresolv

#for rpc
LIBS += -lnsl


