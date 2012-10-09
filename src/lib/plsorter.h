#ifndef PLSORTER_H
#define PLSORTER_H

#include <QObject>
#include <QMap>
#include <QFile>
#include <math.h>

#include "src/lib/reporting.h"

class PLSorter : public QObject
{
    Q_OBJECT
public:
    explicit PLSorter(QObject *parent = 0);
    QString sReturn; //Предполагает вывод готового плейлиста, но думаю вывод будет в json
    void LoadPlayList(QString playlist); //Загрузка плейлиста, пока только из файла

private:
    QList< QPair<QString,quint32> > VideoInfo; //Массив пар имя видео и колличество повторов
    quint32 VideoCounts; //колличество видео
    double VideoCalc[]; //какоято калькуляция чего-то толком не понял
    quint32 GetVideoSummCount(); //сумма видео в плейлисте
    void Sort(); //сортировка
    void DoList(); //делаем плейлист
    
signals:
    
public slots:
    
};

#endif // PLSORTER_H
