#include "qtsocket.h"

// C++
#include <iostream>

namespace mrsockets {

Socket::Socket(QObject *parent) :
    QObject(parent),
    m_isInitOk(false),
    m_state(DISCONNECTED)
{
}


Socket::~Socket()
{
    if (p_socket != 0) {
        delete p_socket;
    }
}


void Socket::init()
{
    if (!m_isInitOk) {
      p_socket = new QTcpSocket(this);
      if (p_socket == 0) {
        m_isInitOk = false;
      } else {
        connect(p_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
                this, SLOT(handleStateChange(QAbstractSocket::SocketState)));

        connect(p_socket, SIGNAL(connected()),
                this, SLOT(handleConnect()));

        connect(p_socket, SIGNAL(disconnected()),
                this, SLOT(handleDisconnect()));

        connect(p_socket, SIGNAL(bytesWritten(qint64)),
                this, SLOT(handleBytesWritten(qint64)));

        connect(p_socket, SIGNAL(readyRead()),
                this, SLOT(handleReadyRead()));

        connect(this, SIGNAL(stateChange(SocketStates)),
                this, SLOT(route()));
        m_isInitOk = true;
      }
    }

    route();
}



void Socket::send(const QString &msg)
{
    qint64 bytes = p_socket->write(msg.toLocal8Bit());
    if (bytes <= 0) {
        m_state = NOT_READY;
    } else {
        m_state = READY;
    }
    route();
}


QByteArray  Socket::recieve()
{
    return QByteArray("");
}


void Socket::route()
{
    switch (m_state) {
    case CONECTED:
        p_socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
        break;
    case DISCONNECTED:

        break;
    case READY:

        break;
    case NOT_READY:

        break;
    }

}


SocketStates Socket::getCurrentState()
{
    return m_state;
}


void Socket::handleReadyRead()
{
    m_state = NOT_READY;

    if (p_socket->canReadLine()) {
        m_bytes = p_socket->readAll();
        std::cout << m_bytes.toStdString() << std::endl; // test
        m_state = READY;
    }

    route();
}


QByteArray Socket::getBytesRead()
{
    return m_bytes;
}

void Socket::connectToHost(const QString &host, quint16 port)
{
    p_socket->connectToHost(host, port);

}


void Socket::handleStateChange(QAbstractSocket::SocketState)
{
}



void Socket::handleConnect()
{
    m_state = CONECTED;
    route();
}


void Socket::handleDisconnect()
{
    m_state = DISCONNECTED;
    route();
}


void Socket::handleBytesWritten(qint64 bytes)
{
    if (bytes > 0) {
        m_state = READY;
    } else {
        m_state = NOT_READY;
    }

    route();
}


} // namespace mrsockets

