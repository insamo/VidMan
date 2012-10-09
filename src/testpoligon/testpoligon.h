#ifndef TESTPOLIGON_H
#define TESTPOLIGON_H

#include <QWidget>

#include "src/lib/plsorter.h"

namespace Ui {
class TestPoligon;
}

class TestPoligon : public QWidget
{
    Q_OBJECT
    
public:
    explicit TestPoligon(QWidget *parent = 0);
    ~TestPoligon();
    
private:
    Ui::TestPoligon *ui;
};

#endif // TESTPOLIGON_H
