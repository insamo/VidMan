#include "clientthread.h"

ClientThread::ClientThread(int handleSocket, QObject *parent) :
    QThread(parent)
{
    this->handleSocket = handleSocket;
}

void ClientThread::run()
{
    QTcpSocket tcpSocket;

    if (!tcpSocket.setSocketDescriptor(handleSocket)) {

        return;
    }


    if(tcpSocket.waitForReadyRead())
    {
        QByteArray block;
        QDataStream in(&block,QIODevice::ReadOnly);
        in.setVersion(QDataStream::Qt_4_8);
        block = tcpSocket.readAll();
        reporting("server read ",1,true);
        QString text;
        in >> text;
        reporting("thred " + text,1,true);

        QByteArray oblock;
        QDataStream out(&oblock, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_8);
        //out << (quint16)0;
        out << text;
        //out.device()->seek(0);
       // out << (quint16)(oblock.size() - sizeof(quint16));

        tcpSocket.write(oblock);
        reporting("server write ",1,true);
        tcpSocket.waitForBytesWritten();
        tcpSocket.disconnectFromHost();
        tcpSocket.waitForDisconnected();
    }
}


