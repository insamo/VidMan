#include "plsorter.h"

PLSorter::PLSorter(QObject *parent) :
    QObject(parent)
{
    this->VideoCounts = 0;
    this->LoadPlayList("playlist.txt");
    this->DoList();
}

void PLSorter::LoadPlayList(QString playlist)
{
    QFile plfile(playlist);

    if(!plfile.open(QIODevice::ReadOnly | QIODevice::Text)) reporting("file not open");

    QString videoname;
    quint32 videocount;

    QPair<QString, quint32> tmp;

    while(!plfile.atEnd())
    {
        videoname = QString(plfile.readLine()).trimmed();
        videocount = QString(plfile.readLine()).trimmed().toInt();
        tmp.first = videoname;
        tmp.second = videocount;
        VideoInfo.append(tmp);
        this->VideoCounts++;
    }

    qDebug()<<VideoInfo;
    qDebug()<<this->VideoCounts;

    plfile.close();

}

quint32 PLSorter::GetVideoSummCount() {

    quint32 result = 0;

    qDebug()<<"GetVideoSummCount";

    for(quint32 i=0;i<=this->VideoCounts-1;++i) {
        result+= this->VideoInfo.at(i).second;
    }

    qDebug()<<"video sum counts"+result;
    return result;
}

void PLSorter::Sort() {
    //Сортировка работает отлично
    qDebug()<<"SORT";
    bool stopRepeat;

    do {
        stopRepeat = true;
        for(quint32 i=0;i<=this->VideoCounts-2; i++) {
            if(this->VideoInfo.at(i).second < this->VideoInfo.at(i+1).second)
            {
                this->VideoInfo.swap(i,i+1);
                stopRepeat = false;
            }
        }
    }
    while(stopRepeat);

    qDebug()<<"endSort";
}


void PLSorter::DoList() {
    this->Sort();
    quint32 SummCount = this->GetVideoSummCount();
    qDebug()<<"--VideoInfo--";
    for(quint32 i=0;i<=this->VideoCounts-1;i++) {
        qDebug()<<this->VideoInfo.at(i).first + ' - ' + quint32(this->VideoInfo.at(i).second);
    }

    qDebug()<<"---VideoCalc---";

    for(quint32 i=0;i<=this->VideoCounts-1;i++) {
        this->VideoCalc[i] = SummCount / this->VideoInfo.at(i).second;
        qDebug()<<this->VideoCalc[i];
    }

    QList<QString> mass;
    //Что то вроде динамического массива, спать хотелось,
    //не хотел искать как же делается настоящий динамичесикй массив,
    //в общем надо исправить, для теста пойдет
    for(quint32 i=0;i<=SummCount-1;i++) { //типо SetLenght, аналог не искал :D, опять же ссылаюсь на сонность
        mass<<"";
    }
    quint32 maxCount;
    double iStep; //грешу на эту переменную, непонял просто что да как
    bool setOnNextStep;
    for(quint32 i=0;i<=this->VideoCounts-1;i++) {
        maxCount = this->VideoInfo.at(i).second;

        do {
            iStep = i;
            setOnNextStep = false;

            for(quint32 j=i;j<=SummCount-1;j++) {

                if(quint32(iStep) == j) {
                    if(mass[j] != "")
                        setOnNextStep = true;
                    else {
                        mass[j]=this->VideoInfo.at(i).first;
                        iStep = iStep + this->VideoCalc[i];
                        setOnNextStep = false;
                        maxCount--;
                    }
                }
                else {
                    if(setOnNextStep && (mass[j]=="")) {
                        mass[j]=this->VideoInfo.at(i).first;
                        iStep += this->VideoCalc[i];
                        maxCount--;
                    }
                }

//                if(maxCount<=0)
//                    break;
            }

        } while(maxCount<=0);

        if((i==this->VideoCounts) && setOnNextStep) {
            for(quint32 j=0;j<=SummCount-1;j++) {
                if(mass[j]=="") {
                    mass[j] = this->VideoInfo.at(i).first;
                    break;
                }
            }
        }
    }

    qDebug()<<mass;
    for(quint32 i = 0; i<=SummCount-1;i++) {
        qDebug()<<i + ' : ' + mass[i];
    }

}
