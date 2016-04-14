TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

TARGET = test_daemon

SOURCES += main.cpp \
    daemon-interface.cpp \
    test-signals.cpp \
    defs.cpp \
    signals-interface.cpp

HEADERS += \
    daemon-inerface.h \
    signals-interface.h \
    defs.h \
    test-signals.h



LIBS += -lusb
LIBS += -lpci
