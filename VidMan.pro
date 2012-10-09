SOURCES += \
    main.cpp \
    src/testpoligon/testpoligon.cpp \
    src/clientserver/clientthread.cpp \
    src/lib/reporting.cpp \
    src/clientserver/tcpserver.cpp \
    src/clientserver/tcpclient.cpp \
    src/lib/plsorter.cpp

QT += phonon, network

HEADERS += \
    src/testpoligon/testpoligon.h \
    src/clientserver/clientthread.h \
    src/lib/reporting.h \
    src/clientserver/tcpclient.h \
    src/clientserver/tcpserver.h \
    src/lib/plsorter.h

FORMS += \
    src/testpoligon/testpoligon.ui
