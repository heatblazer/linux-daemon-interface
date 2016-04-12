#pragma once
#ifndef DEFS
#define DEFS

#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <signal.h>


#define LOG_FILE "log.txt"
void writer(const char* msg);
typedef void (*pSignalHanlder)(int);


#endif // DEFS

