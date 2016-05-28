#ifndef QTLOGGER_H
#define QTLOGGER_H

#include <QIODevice>
#include <QtCore>

class MyLogger
{
public:
    static void log(const QString& msg);

private:
    static bool isOpen;
    static QFile* file;
    static QTextStream* stream;


};


#endif // QTLOGGER_H
