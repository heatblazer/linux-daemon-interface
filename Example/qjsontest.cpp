#include "qjsontest.h"

// JsonRPC
#include "jsonrpc/peer.h"
#include "jsonrpc/responsehandler.h"

// Qt network
#include <QTcpServer>
#include <QTcpSocket>


// C++ std
#include <iostream>


namespace  JsonRPC {



QHBoxLayout QRpc::hlayout;


QRpc::QRpc(const QString &name, QObject *parent) :
    QObject(parent),
    peer(new JsonRPC::Peer(this)),
    serverSocket(new QTcpServer(this)),
    socket(NULL),
    clientSocket(new QTcpSocket(this)),
    clientMessageSize(0)
{
    // connect all signals to all slots
    connect(peer, SIGNAL(readyRequest(QSharedPointer<JsonRPC::ResponseHandler>)),
            this, SLOT(onReadyRequest(QSharedPointer<JsonRPC::ResponseHandler>)));
    connect(peer, SIGNAL(readyResponseMessage(QByteArray)),
            this, SLOT(onReadyResponseMessage(QByteArray)));

    connect(peer, SIGNAL(readyRequestMessage(QByteArray)),
            this, SLOT(onReadyRequestMessage(QByteArray)));
    connect(peer, SIGNAL(readyResponse(QVariant,QVariant)),
            this, SLOT(onReadyResponse(QVariant,QVariant)));


    connect(serverSocket, SIGNAL(newConnection()),
            this, SLOT(onNewConnection()));

    connect(&m_button, SIGNAL(clicked(bool)),
            this, SLOT(onButtonClick()));

    connect(clientSocket, SIGNAL(connected()),
            this, SLOT(onClientSocketConnected()));
    connect(clientSocket, SIGNAL(readyRead()),
            this, SLOT(onReadyRead()));
    connect(clientSocket, SIGNAL(disconnected()),
            this, SLOT(onDisconnected()));

    serverSocket->listen(QHostAddress::Any);


    // gui features
    m_button.setText(name);
    m_button.setMinimumHeight(200);
    m_button.setMinimumWidth(200);
    hlayout.addWidget(&m_button);

}


QRpc::~QRpc()
{

}

void QRpc::onReadyRequest(const QSharedPointer<JsonRPC::ResponseHandler> &handler)
{
    std::cout << "ready request\n";

    if (handler->method() == "echo") {
        handler->response("okay");

        QString text;
        QDebug dbg(&text);
        dbg << handler->params();

    } else {
        handler->error(Error(METHOD_NOT_FOUND));
    }

}

void QRpc::onReadyResponseMessage(const QByteArray &message)
{
    std::cout << "Ready response message\n";
    QDataStream stream(socket);
    quint8 messageSize = message.size();
    stream << messageSize;
    socket->write(message);
}

void QRpc::onReadyRequestMessage(const QByteArray &message)
{
    std::cout << "Ready request message\n";
    QDataStream stream(clientSocket);
    quint8 messageSize = message.size();
    stream << messageSize;
    clientSocket->write(message);

}

void QRpc::onReadyResponse(const QVariant &result, const QVariant &id)
{
    clientSocket->disconnectFromHost();

}

void QRpc::onNewConnection()
{
    std::cout << "New connection\n";
    if (socket != nullptr) {
        delete serverSocket->nextPendingConnection();
        return;
    }

    socket = serverSocket->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()),
            this, SLOT(onDisconnected()));

    buffer.clear();
    messageSize = 0;

}

void QRpc::onReadyRead()
{
    std::cout << "Ready read\n";
    if (!messageSize) {
        QDataStream stream(socket);
        stream >> messageSize;
    }

    buffer.append(socket->readAll());

    if (messageSize && buffer.size() >= messageSize) {
        peer->handleMessage(buffer.left(messageSize));
        buffer.remove(0, messageSize);

        if (buffer.size()) {
            QDataStream stream(socket);
            stream >> messageSize;
            buffer.append(socket->readAll());
        } else {
            messageSize = 0;
        }
    }
}



void QRpc::onDisconnected()
{
    std::cout << "Disconnected\n";
    socket->deleteLater();
    socket = NULL;
}



// these will be removed and the simple buttos from my prev Ami will be used


void QRpc::onButtonClick()
{
    clientSocket->connectToHost(QHostAddress::LocalHost, 8080);

}

void QRpc::onClientSocketConnected()
{
    QVariantList params;
    params.push_back("Hello");
    params.push_back("World");
    peer->call("echo", params, QUuid::createUuid().toString());
}

void QRpc::onClientSocketReadyRead()
{
    if (!clientMessageSize) {
        QDataStream stream(clientSocket);
        stream >> clientMessageSize;
    }

    clientBuffer.append(clientSocket->readAll());
    if (clientMessageSize
            && clientBuffer.size() >= clientMessageSize) {
        peer->handleMessage(clientBuffer.left(clientMessageSize));
        clientBuffer.remove(0, clientMessageSize);

        if (clientBuffer.size()) {
            QDataStream stream(clientSocket);
            stream >> clientMessageSize;
            clientBuffer.append(clientSocket->readAll());
        } else {
            clientMessageSize = 0;
        }
    }
}

void QRpc::onClientDisconnected()
{

}

} // JsonRPC
