#include <QApplication>

#include "src/clientserver/TCPServer.h"
#include "src/clientserver/TCPClient.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    TCPServer server;

    //TCPClient client;


    return a.exec();
}
