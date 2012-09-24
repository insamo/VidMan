#include "testpoligon.h"
#include "ui_testpoligon.h"

TestPoligon::TestPoligon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestPoligon)
{
    ui->setupUi(this);
}

TestPoligon::~TestPoligon()
{
    delete ui;
}
