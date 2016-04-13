#include <iostream>
#include "daemon-inerface.h"
#include <stdlib.h>

//!!! THE TEST MAIN FUNCTION
using namespace std;

//test some works


int work1(int a, void* pdata)
{
    (void)a;
    (void) pdata;
    writer("Worker 1 registerd... do some tasks...\n");
}

int work2(int a, void* pdata)
{
    (void)a;
    (void) pdata;

    writer("Worker 2 registerd... do some tasks...\n");
}

int work3(int a, void* pdata)
{
    (void)a;
    (void) pdata;

    writer("Worker 3 registerd... do some tasks...\n");
}

int work4(int a, void* pdata)
{
    (void)a; (void) pdata;
    writer("Worker 4 registerd... do some work\n");
}

#define MIN 60
#define HR (MIN * 60 )

int main(int argc, char** argv)
{
    Daemon daemon1;
    Daemon::set_sleep_time(MIN * 5);

//! IMPORTANT TODO: tasks must be in separate threads
//!
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

