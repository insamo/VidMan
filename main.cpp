#include <QApplication>

#include "src/clientserver/TCPServer.h"
#include "src/clientserver/TCPClient.h"
#include "src/testpoligon/testpoligon.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //TCPServer server;

    //TCPClient client;

    //������� ��� ������, �� ���� ������ ���������� �����
    TestPoligon testPoligon;

    testPoligon.show();

    return a.exec();
}
