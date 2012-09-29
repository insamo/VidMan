#include "reporting.h"

reporting::reporting(QString msg, quint8 type,bool console, QObject *parent):
    QObject(parent)
{

    reportBegin = QTime::currentTime().toString()+" >> ";
    reportMsg = msg;
    reportType = type;
    bConsole = console;

    if(!path.exists("logs")) {
        path.mkdir("logs");
    }
    log.setFileName("logs/"+QDate::currentDate().toString("yyyyMMdd")+".log");
    log.open(QIODevice::Append);

    write();
}

reporting::~reporting()
{
    log.flush();
    log.close();
}

void reporting::write()
{
    QTextStream in(&log);

    switch (reportType) {
    case 0:
        if(bConsole) qDebug()<<cmdGREEN<<"[OK] "+reportBegin+reportMsg<<cmdNC;
        in<<"[OK] "+reportBegin<<reportMsg<<endl;
        break;
    case 1:
        if(bConsole) qDebug()<<cmdYELLOW<<"[WARNING] "+reportBegin+reportMsg<<cmdNC;
        in<<"[WARNING] "<<reportBegin<<reportMsg<<endl;
        break;
    case 2:
        if(bConsole) qDebug()<<cmdRED<<"[ERROR] "+reportBegin+reportMsg<<cmdNC;
        in<<"[ERROR] "<<reportBegin<<reportMsg<<endl;
        break;
    case 3:
        if(bConsole) qDebug()<<cmdCYAN<<"[INFO]"+reportMsg<<cmdNC;
        in<<"[INFO] "<<reportBegin<<reportMsg<<endl;
        break;
    }

    deleteLater();

}
