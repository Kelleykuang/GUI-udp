#-------------------------------------------------
#
# Project created by QtCreator 2019-04-25T19:20:43
#
#-------------------------------------------------

QT       += core gui
QT       += core
QT       += network
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = udp_receiver
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11
CONFIG += resources_big
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += \
        main.cpp \
    record.cpp \
    udpreceiver.cpp \
    paint.cpp \
    common.cpp

HEADERS += \
    UdpReceiver.h \
    paint.h \
    record.h \
    common.h

FORMS += \
        mainwindow.ui
