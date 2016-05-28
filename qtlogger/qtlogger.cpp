#include "qtlogger.h"


QFile*          MyLogger::file = new QFile("test_daemon.log");

QTextStream*    MyLogger::stream = new QTextStream(file);

bool            MyLogger::isOpen = false;

void            MyLogger::log(const QString &msg)
{
    if(!isOpen) {
        isOpen = true;
        file->open(QIODevice::ReadWrite);
    }
    *stream << msg ;
}
