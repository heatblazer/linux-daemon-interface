#include "cthread.h"
#include <stdio.h>

CXThread::CXThread()
{

}


CXThread::~CXThread()
{

}




void CXThread::init(size_t stackSize, pthread_cb foo, void* userData)
{
   static int is_init = 0;
   if (is_init == 0) {
       is_init = 1;
        if (stackSize <= 0) {
            stackSize = 128 * 1024; // 128 k stack
        }
       m_cb = foo;
       pthread_attr_init(&m_attr);
       pthread_attr_setstacksize(&m_attr, stackSize);
       pthread_create(&m_thread, &m_attr, m_cb, userData);

   } // never call init second time
}


void CXThread::join()
{
    pthread_join(m_thread, NULL);
}



