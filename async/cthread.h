#ifndef CTHREAD
#define CTHREAD

#include <pthread.h>


class CXThread
{

public:
    CXThread();
    virtual ~CXThread();

    void init(void /* TODO add parameters */);
    static void* run(void* args);


protected:
private:
    pthread_t m_thread;

};

#endif // CTHREAD

