#include <QApplication>

#include "src/clientserver/TCPServer.h"
#include "src/clientserver/TCPClient.h"
#include "src/testpoligon/testpoligon.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //TCPServer server;

    //TCPClient client;

    //ѕолигон дл€ тестов, он пока просто показывает форму
    TestPoligon testPoligon;

    testPoligon.show();

    return a.exec();
}
