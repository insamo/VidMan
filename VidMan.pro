SOURCES += \
    main.cpp \
    src/testpoligon/testpoligon.cpp \
    src/clientserver/TCPServer.cpp \
    src/clientserver/TCPClient.cpp \
    src/clientserver/clientthread.cpp \
    src/lib/reporting.cpp

QT += phonon, network

HEADERS += \
    src/testpoligon/testpoligon.h \
    src/clientserver/TCPServer.h \
    src/clientserver/TCPClient.h \
    src/clientserver/clientthread.h \
    src/lib/reporting.h

FORMS += \
    src/testpoligon/testpoligon.ui
