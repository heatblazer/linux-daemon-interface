#include <iostream>
#include "daemon-inerface.h"
#include "defs.h"
#include <stdlib.h>
#include <pthread.h>

//!!! THE TEST MAIN FUNCTION
using namespace std;

//test some works


int work1(int a, void* pdata)
{
    ENTER_CRITICAL_SECTION;
    (void)a;
    (void) pdata;
    writer("Worker 1 registerd... do some tasks...\n");
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
    writer("Worker 3 registerd... do some tasks...\n");
    LEAVE_CRITICAL_SECTION;
    return 0;
}

int work4(int a, void* pdata)
{
    ENTER_CRITICAL_SECTION;
    (void)a; (void) pdata;
    writer("Worker 4 registerd... do some work\n");
    LEAVE_CRITICAL_SECTION;
    return 0;
}

#define MIN 60
#define HR (MIN * 60 )

int main(int argc, char** argv)
{
    Daemon daemon1;
    Daemon::set_sleep_time(MIN * 5);

//! IMPORTANT TODO: tasks must be in separate threads
//!
//! update: tasks can enter in critical sections
    daemon1.registerTask(1, work1, 0, 0);
    daemon1.registerTask(2, work2, 0, 0);
    daemon1.registerTask(3, work3, 0, 0);
    daemon1.registerTask(4, work4, 0,0);
//known bug with deregistering tasks

//TODO!
//register before start, for more flexible interface use
// register and deregister in separate threads
    daemon1.start(argc, argv);


    return 0;
}

