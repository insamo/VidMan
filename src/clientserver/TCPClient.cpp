#include "TCPClient.h"

TCPClient::TCPClient(QObject *parent) :
    QObject(parent)
{
    tcpSocket = new QTcpSocket(this);

    QString ip = "192.168.234.129";
    quint16 port = 50000;

    tcpSocket->connectToHost(ip,port);

    if(tcpSocket->waitForConnected()) {
        QString text = "fuck";
        QByteArray oblock;
        QDataStream out(&oblock, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_8);
        //out << (quint16)0;
        out << text;
        //out.device()->seek(0);
        //out << (quint16)(oblock.size() - sizeof(quint16));

        tcpSocket->write(oblock);
        reporting("client write ",1,true);

        if(tcpSocket->waitForBytesWritten()) {
            QByteArray block;
            QDataStream in(&block,QIODevice::ReadOnly);
            in.setVersion(QDataStream::Qt_4_8);
            tcpSocket->waitForReadyRead();
            block = tcpSocket->readAll();
            reporting("client readAll ",1,true);
            text = "";
            in >> text;
            reporting("client " + text,1,true);
        }

        tcpSocket->disconnectFromHost();
        tcpSocket->waitForDisconnected();
    }
}
