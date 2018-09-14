#-------------------------------------------------
#
# Project created by QtCreator 2017-08-01T14:42:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = showP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myscene.cpp \
    mypicitem.cpp

HEADERS  += mainwindow.h \
    myscene.h \
    mypicitem.h

FORMS    += mainwindow.ui

RESOURCES += \
    pic.qrc
