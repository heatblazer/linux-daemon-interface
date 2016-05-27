#pragma once
#include <QtCore>



namespace JsonRPC {

class Peer;
class ResponseHandler;

} // namespace JsonRPC

class QTcpServer;
class QTcpSocket;

class QRpc : public QObject
{
    Q_OBJECT

public:
    explicit QRpc(QObject *parent = 0);
    ~QRpc();

// FIXME implement all handles later
#if 0
private slots:
    void onReadyRequest(const QSharedPointer<JsonRPC::ResponseHandler> &handler);
    void onReadyResponseMessage(const QByteArray &message);

    void onReadyRequestMessage(const QByteArray &message);
    void onReadyResponse(const QVariant &result,const QVariant &id);

    void onNewConnection();
    void onReadyRead();
    void onDisconnected();

    void onButtonClick();
    void onClientSocketConnected();
    void onClientSocketReadyRead();
    void onClientDisconnected();
#endif
private:

    JsonRPC::Peer *peer;

    QTcpServer *serverSocket;
    QTcpSocket *socket;
    QByteArray buffer;
    quint8 messageSize;

    QTcpSocket *clientSocket;
    QByteArray clientBuffer;
    quint8 clientMessageSize;
};
