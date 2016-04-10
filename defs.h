#pragma once
#ifndef DEFS
#define DEFS

#define LOG_FILE "log.txt"
void writer(const char* msg);
typedef void (*pSignalHanlder)(int);


#endif // DEFS

