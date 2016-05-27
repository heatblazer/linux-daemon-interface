#include "msg.h"

namespace mrsockets {


Msg::Msg() : m_isValid(true) // assuming its OK by default
{

}


Msg::~Msg()
{

}

//! byte array builder
//! \brief Msg::append
//! \param msg
//! \param isValid
//! \return
//!
Msg& Msg::append(const char *msg, bool *isValid)
{
    // check by other criteria for now just check if there is a msg in all
    // calls for the chaining ...
    if (msg) {
        *isValid &= true;
    } else {
        *isValid &= false;
    }

    m_message.append(msg);
    // if needed append newlines or cutom formating
    return *this;
}

Msg &Msg::append(const char *msg)
{
    return append(msg, &m_isValid);
}


QByteArray  Msg::submit(bool isValid)
{
    if (isValid) {
        return m_message.toLocal8Bit();
    } else {
        return QByteArray(""); // empty array
    }
}

QByteArray Msg::submit()
{
    return submit(m_isValid);
}



}
