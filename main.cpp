#include <iostream>
#include "daemon-inerface.h"

using namespace std;

int main(int argc, char** argv)
{
    Daemon daemon1;
    Daemon::set_sleep_time(3);

    daemon1.start(argc, argv);


    return 0;
}

