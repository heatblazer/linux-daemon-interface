// own headers
#include "daemon-inerface.h"
#include "defs.h"
#include "async/cthread.h"
#include "network/csocket.h"

// use Qt TcpSockets
// Qt
#include <QtCore>
#include "network/qtsocket.h"
// C++
#include <iostream>

// ANIS C
#include <stdlib.h>
#include <time.h>



//test tasks
///1. list new usb devices when plugged
#include <stdio.h>

//test some d-bus
///2. message some logs with dbus

#define LINE_80 "------------------------------------------------------------------------\n"
static void list_usb(void)
{
#if 0
    fprintf(stdout, "%s", LINE_80);
    fprintf(stdout, "USB devices:\n");

    usb_init();
    unsigned int busses =  usb_find_busses();
    unsigned int devices = usb_find_devices();
    fprintf(stdout, "Busses: [%d]\tDevices: [%d]\n", busses, devices);

    struct usb_bus* bus = NULL;
    struct usb_device*     udev = NULL;


    for ( bus = usb_busses; bus != NULL; bus = bus->next)
    {
        for ( udev = bus->devices; udev != NULL; udev = udev->next )
        {
            char msg_buffer[64] = {0};
            sprintf(msg_buffer, "[%04x][%04x]\n", udev->descriptor.idVendor,
                                                   udev->descriptor.idProduct);
            writer(msg_buffer);

        }
    }
    fprintf(stdout, "%s", LINE_80);
#endif
}


//!!! THE TEST MAIN FUNCTION
using namespace std;

int main(int argc, char** argv)
{

//    Daemon::set_sleep_time(MIN * 5);
//    Daemon daemon1;

//! IMPORTANT TODO: tasks must be in separate threads
//!
//! update: tasks can enter in critical sections

//      daemon1.registerTask(1, work1, 0, 0);
//      daemon1.registerTask(2, work2, 0, 0);
//      daemon1.registerTask(3, work3, 0, 0);
//      daemon1.registerTask(4, work4, 0,0);
//known bug with deregistering tasks

//TODO!
//register before start, for more flexible interface use
// register and deregister in separate threads
//     daemon1.start(argc, argv);

    QCoreApplication ap(argc, argv);
    mrsockets::Socket s;
    s.init();
    s.init();
    s.connectToHost("127.0.0.1", 8080);
    s.send("");

    return ap.exec();
#if 0
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
#endif // not QT based

}

