#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include "src/lib/reporting.h"
class ClientThread : public QThread
{
    Q_OBJECT
public:
    ClientThread(int handleSocket, QObject *parent = 0);
    void run();

private:
    int handleSocket;
    
signals:

    
public slots:

};

#endif // CLIENTTHREAD_H
