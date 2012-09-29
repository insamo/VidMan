#include "TCPServer.h"

TCPServer::TCPServer(QObject *parent) :
    QTcpServer(parent)
{
    ip = "127.0.0.1";
    port = 50000;
    this->listen(QHostAddress(ip),port);
}

void TCPServer::incomingConnection(int handle)
{
    ClientThread *thread = new ClientThread(handle, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
