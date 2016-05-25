#include "cthread.h"
#include <stdio.h>

CXThread::CXThread()
{

}


CXThread::~CXThread()
{

}


void CXThread::init()
{
   static int is_init = 0;
   if (is_init == 0) {
       is_init = 1;

       pthread_create(&m_thread, NULL, CXThread::run, NULL);
       pthread_join(m_thread, NULL);
   } // never call init second time
}

void* CXThread::run(void* args)
{
    // register the loop
    while (1) {
    }
}
