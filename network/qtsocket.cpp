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
    for(int i=0; i < SocketServer::SIZE; ++i){
        if (p_sockets[i]) {
            delete p_sockets[i];
            p_sockets[i] = nullptr;
        }
    }
}


void Socket::init()
{
    if (!m_isInitOk) {
      p_sockets[SocketServer::SOCKET] = new QTcpSocket(this);
      if (p_sockets[SocketServer::SOCKET] == 0) {
        m_isInitOk = false;
      } else {
        connect(p_sockets[SocketServer::SOCKET], SIGNAL(stateChanged(QAbstractSocket::SocketState)),
                this, SLOT(handleStateChange(QAbstractSocket::SocketState)));

        connect(p_sockets[SocketServer::SOCKET], SIGNAL(connected()),
                this, SLOT(handleConnect()));

        connect(p_sockets[SocketServer::SOCKET], SIGNAL(disconnected()),
                this, SLOT(handleDisconnect()));

        connect(p_sockets[SocketServer::SOCKET], SIGNAL(bytesWritten(qint64)),
                this, SLOT(handleBytesWritten(qint64)));

        connect(p_sockets[SocketServer::SOCKET], SIGNAL(readyRead()),
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
    qint64 bytes = p_sockets[SocketServer::SOCKET]->write(msg.toLocal8Bit());
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
        p_sockets[SocketServer::SOCKET]->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
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

    if (p_sockets[SocketServer::SOCKET]->canReadLine()) {
        m_bytes = p_sockets[SocketServer::SOCKET]->readAll();
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
    p_sockets[SocketServer::SOCKET]->connectToHost(host, port);

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

