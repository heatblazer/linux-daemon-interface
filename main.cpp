// own headers
#include "async/cthread.h"
#include "daemon-inerface.h"
#include "defs.h"
#include "Example/qjsontest.h"
#include "tests.h"
#include "network/csocket.h"
#include "network/msg.h"
#include "network/qtsocket.h"

// Qt
#include <QtCore>
#include <QApplication>

// C++
#include <iostream>


//!!! THE TEST MAIN FUNCTION

int main(int argc, char** argv)
{

    return test0(argc, argv);

}


int test0(int argc, char** argv) {


    QCoreApplication ap(argc, argv);
    mrsockets::Socket s;
    s.init();
    s.init();
    s.connectToHost("google.com", 80);

    mrsockets::Msg msg;

    // this is to be made private

    QByteArray msgtosend = msg.append("HEAD HTTP/1.0")
       .append("\r\n\r\n\r\n")
       .submit();

    s.send(QString(msgtosend));

    return ap.exec();

}

int test1(int argc, char** argv)
{
    Daemon::set_sleep_time(5);
    Daemon daemon1;

    //! IMPORTANT TODO: tasks must be in separate threads
    //!
    //! update: tasks can enter in critical sections


    daemon1.start(argc, argv);
}



int test2(int argc, char** argv)
{
    srand(time(0));

    CSocket s;

    if (!s.Connect("127.0.0.1", "8080") == 0) {
        return 1;
    }
    //s.Bind("192.168.32.89", "5038");

    for(;;) {
        s.Send("Hello world");
        usleep(0);
    }

    return 0;

}



int test3(int argc, char** argv)
{
    QApplication ap(argc, argv);


    JsonRPC::QRpc rpc("RPC");
    QWidget mw;
    mw.setLayout((QHBoxLayout*)&JsonRPC::QRpc::hlayout);
    mw.show();

    return ap.exec();

}

