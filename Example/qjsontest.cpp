#include "qjsontest.h"

// JsonRPC
#include "jsonrpc/peer.h"
#include "jsonrpc/responsehandler.h"

// Qt network
#include <QTcpServer>
#include <QTcpSocket>



QRpc::QRpc(QObject *parent) :
    QObject(parent),
    peer(new JsonRPC::Peer(this)),
    serverSocket(new QTcpServer(this)),
    socket(NULL),
    clientSocket(new QTcpSocket(this)),
    clientMessageSize(0)
{
    // connect all signals to all slots
}


QRpc::~QRpc()
{

}

