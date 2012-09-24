SOURCES += \
    main.cpp \
    src/clientserver/client.cpp \
    src/clientserver/server.cpp \
    src/testpoligon/testpoligon.cpp

QT += phonon, network

HEADERS += \
    src/clientserver/client.h \
    src/clientserver/server.h \
    src/testpoligon/testpoligon.h

FORMS += \
    src/testpoligon/testpoligon.ui
