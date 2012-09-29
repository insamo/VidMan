#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "src/lib/reporting.h"

class TCPClient : public QObject
{
    Q_OBJECT
public:
    explicit TCPClient(QObject *parent = 0);
    
signals:
    
public slots:

private:
    QTcpSocket *tcpSocket;
    
};

#endif // CLIENT_H
