#pragma once
#include <QtCore>
#include <QThread>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>


namespace JsonRPC {

class Peer;
class ResponseHandler;



class QRpc : public QObject
{
    Q_OBJECT

public:
    explicit QRpc(const QString& name, QObject *parent = 0);
    ~QRpc();

// FIXME implement all handles later
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

private:

    JsonRPC::Peer *peer;

    QTcpServer *serverSocket;
    QTcpSocket *socket;
    QByteArray buffer;
    quint8 messageSize;

    QTcpSocket *clientSocket;
    QByteArray clientBuffer;
    quint8 clientMessageSize;

public:
    static QHBoxLayout hlayout;

private:
    // gui members
    QPushButton     m_button;
    QString         m_name;



};

}
