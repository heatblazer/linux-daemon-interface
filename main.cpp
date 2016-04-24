#include <iostream>
#include "daemon-inerface.h"
#include "defs.h"
#include <stdlib.h>
#include <pthread.h>

//test tasks
///1. list new usb devices when plugged
#include <usb.h>
#include <stdio.h>

//test some d-bus
///2. message some logs with dbus

#define LINE_80 "------------------------------------------------------------------------\n"
static void list_usb(void)
{

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
}


//!!! THE TEST MAIN FUNCTION
using namespace std;

//test some works


int work1(int a, void* pdata)
{
    ENTER_CRITICAL_SECTION;
    (void)a;
    (void) pdata;
    writer("Worker 2 registerd... do some tasks...\n");
    LEAVE_CRITICAL_SECTION;

    return 0;
}

int work2(int a, void* pdata)
{
    ENTER_CRITICAL_SECTION;
    (void)a;
    (void) pdata;
    writer("Worker 2 registerd... do some tasks...\n");
    LEAVE_CRITICAL_SECTION;
    return 0;
}

int work3(int a, void* pdata)
{
    ENTER_CRITICAL_SECTION;
    (void)a;
    (void) pdata;
    list_usb();
    LEAVE_CRITICAL_SECTION;
    return 0;
}

int work4(int a, void* pdata)
{
    ENTER_CRITICAL_SECTION;
    (void)a;
    (void) pdata;
    writer("Worker 2 registerd... do some tasks...\n");
    LEAVE_CRITICAL_SECTION;

    return 0;
}

#define MIN 60
#define HR (MIN * 60 )

int main(int argc, char** argv)
{
    Daemon::set_sleep_time(MIN * 5);


    Daemon daemon1;

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
     daemon1.start(argc, argv);


    return 0;
}

