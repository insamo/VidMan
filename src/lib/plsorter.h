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
    QString sReturn; //������������ ����� �������� ���������, �� ����� ����� ����� � json
    void LoadPlayList(QString playlist); //�������� ���������, ���� ������ �� �����

private:
    QList< QPair<QString,quint32> > VideoInfo; //������ ��� ��� ����� � ����������� ��������
    quint32 VideoCounts; //����������� �����
    double VideoCalc[]; //������� ����������� ����-�� ������ �� �����
    quint32 GetVideoSummCount(); //����� ����� � ���������
    void Sort(); //����������
    void DoList(); //������ ��������
    
signals:
    
public slots:
    
};

#endif // PLSORTER_H
