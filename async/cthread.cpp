#include "cthread.h"
#include <stdio.h>

CXThread::CXThread()
{

}


CXThread::~CXThread()
{

}

//! Init a pthread and pass a worker function to it
//! \brief CXThread::init
//! \param stackSize - set stack size
//! \param foo  - the function to be called as a cb
//! \param userData - pass the usr data
//! \param prio - set priority 1 - 20 unix
//! \param isDetached - detach the thread unable to join with others
//!
void CXThread::init(size_t stackSize, pthread_cb foo, void* userData,
                    int prio, bool isDetached)
{
   static int is_init = 0;
   if (is_init == 0) {
       is_init = 1;
        if (stackSize <= 0) {
            stackSize = 128 * 1024; // 128 k stack
       }
       // better priorities in the future when more threads are needed
       if (prio < 1) {
           prio = 15;
       }

       m_cb = foo;
       pthread_attr_init(&m_attr);


       // set priority
       sched_param param;
       pthread_attr_getschedparam(&m_attr, &param);
       param.__sched_priority = prio;
       pthread_attr_setschedparam(&m_attr, &param);

       // set stack size
       pthread_attr_setstacksize(&m_attr, stackSize);
       // make it run independantly
       if (isDetached) {
           pthread_detach(m_thread);
       }

       pthread_create(&m_thread, &m_attr, m_cb, userData);
   } // never call init second time
}

//! join a joinable thread watch if not detached
//! \brief CXThread::join
//!
void CXThread::join()
{
    static int oneshot = 0;
    if (oneshot < 1) {
        oneshot = 1;
        pthread_join(m_thread, NULL);
    }
}



