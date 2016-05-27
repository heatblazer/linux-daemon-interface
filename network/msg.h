#ifndef MSG_H
#define MSG_H

#include <QByteArray>
#include <QString>


namespace mrsockets {
// simple class to build server client messages
class Msg
{
public:

    explicit Msg();
    virtual ~Msg();

    // TODO make the bool var check private so user don`t bother with the
    // checking, or leave it alone if the user want`s to bother with it
    virtual Msg&        append(const char* msg, bool* isValid);
    virtual Msg&        append(const char* msg);

    virtual QByteArray  submit(bool isValid);
    virtual QByteArray  submit(void);


private:
    bool    m_isValid;
    QString m_message;
};


}
#endif // MSG_H
