#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "src/clientserver/clientthread.h"

class TCPServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TCPServer(QObject *parent = 0);

private:
    QString ip;
    quint16 port;
    
protected:
    void incomingConnection(int handle);
    
public slots:
    
};

#endif // SERVER_H
