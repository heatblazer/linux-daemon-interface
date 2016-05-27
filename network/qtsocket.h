#ifndef SOCKET_H
#define SOCKET_H

// the socket
#include <QTcpSocket>

namespace mrsockets {


enum SocketStates {
    CONECTED,
    DISCONNECTED,
    READY,
    NOT_READY
};


class Socket : public QObject
{
Q_OBJECT


public:
    explicit Socket(QObject* parent = 0);
    virtual ~Socket();
    void init(void);
    SocketStates        getCurrentState(void);
    QByteArray          getBytesRead(void);

    virtual void        connectToHost(const QString& host, quint16 port);
    virtual void        send(const QString& msg);
    virtual QByteArray  recieve(void);


signals:
    void stateChange(SocketStates states);

private slots:
    void handleStateChange(QAbstractSocket::SocketState);
    void handleConnect();
    void handleDisconnect();
    void handleBytesWritten(qint64 bytes);
    void handleReadyRead();

private slots:
    void route(void);

private:
    bool            m_isInitOk;
    SocketStates    m_state;
    QByteArray      m_bytes;

    QTcpSocket*     p_socket;

};

} // namespace mrsockets
#endif // SOCKET_H
