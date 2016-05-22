QT += core
QT += network


CONFIG += c++11
CONFIG += console


TARGET = test_daemon

SOURCES += main.cpp \
    daemon-interface.cpp \
    test-signals.cpp \
    defs.cpp \
    signals-interface.cpp \
    watchdog.cpp \
    schedulers.cpp \
    qtsocket.cpp

HEADERS += \
    daemon-inerface.h \
    signals-interface.h \
    defs.h \
    test-signals.h \
    watchdog.h \
    schedulers.h \
    qtsocket.h


#for threads
LIBS += -lpthread

#for C sockets
LIBS += -lnsl
LIBS += -lresolv
