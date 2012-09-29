#ifndef REPORTING_H
#define REPORTING_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QDateTime>
#include <QTextStream>

#include "src/cmdcolor.h"

class reporting : public QObject
{
    Q_OBJECT
public:
    reporting(QString msg,quint8 type = 0,bool console = false, QObject *parent = 0);

    ~reporting();
private:
    void write();

    QDir path;
    QFile log;
    QString reportBegin;
    QString reportMsg;
    quint8 reportType;
    bool bConsole;
signals:

public slots:

};

#endif // REPORTING_H
