TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = build
TARGET = test_daemon

SOURCES += main.cpp \
    daemon-interface.cpp \
    test-signals.cpp \
    defs.cpp \
    signals-interface.cpp \
    watchdog.cpp \
    schedulers.cpp \
    socket.cpp

HEADERS += \
    daemon-inerface.h \
    signals-interface.h \
    defs.h \
    test-signals.h \
    watchdog.h \
    schedulers.h \
    socket.h


RESOURCES += rpc/hello.x

#LIBS += -lusb
#for threads
LIBS += -lpthread

#for rpc services
LIBS += -lrpcsvc

#for sockets
LIBS += -lnsl
LIBS += -lresolv
