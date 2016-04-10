TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    daemon-interface.cpp \
    radis-signals.cpp \
    defs.cpp \
    signals-interface.cpp

HEADERS += \
    daemon-inerface.h \
    signals-interface.h \
    defs.h \
    radis-signals.h

