#include <QApplication>
//#include <phonon/AudioOutput>
//#include <phonon/MediaObject>

#include <QLabel>
#include <QUrl>
#include <phonon/VideoPlayer>
#include <QtOpenGL/QtOpenGL>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


//    Phonon::MediaObject object;

//    Phonon::AudioOutput output;

//    object.setCurrentSource(Phonon::MediaSource("D:\\Music\\ne_budite_spyashih_-_budu_molodm_pogibat.mp3"));

//    Phonon::createPath(&object, &output);

//    object.play();

    a.setApplicationName("test");

    QLabel  l;
    l.setGeometry(100,100,200,200);
    Phonon::VideoPlayer* player = new Phonon::VideoPlayer(Phonon::VideoCategory, &l);
    player->play(QUrl::fromLocalFile("D:\\Video\\Pritvoris.moey.jenoy.f-s.Mgt.DVDRip.avi"));
    l.show();

    return a.exec();
}
