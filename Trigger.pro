QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = smtp
TEMPLATE = app

CONFIG += c++11
QT += gui widgets
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Beacon.cpp \
    Location.cpp \
    LocationCalculator.cpp \
    Receiver.cpp \
    log_in.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    smtp.cpp

HEADERS += \
    Beacon.h \
    Location.h \
    LocationCalculator.h \
    Receiver.h \
    log_in.h \
    mainwindow.h \
    map.h \
    smtp.h

FORMS += \
    log_in.ui \
    mainwindow.ui \
    map.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
