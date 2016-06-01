#ifndef CTHREAD
#define CTHREAD

#include <pthread.h>


typedef void* (*pthread_cb)(void*);

class CXThread
{

public:
    CXThread();
    virtual ~CXThread();

    void init(size_t stackSize, pthread_cb foo, void* userData, int prio, bool isDetached);
    void join(void);

protected:
private:
    pthread_cb      m_cb;
    pthread_t       m_thread;
    pthread_attr_t  m_attr;
    void*           p_usrData;

};

#endif // CTHREAD

