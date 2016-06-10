#-------------------------------------------------
#
# Project created by QtCreator 2016-06-07T12:17:38
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clisupport.cpp

HEADERS  += mainwindow.h \
    clisupport.h

FORMS    += mainwindow.ui \
    clisupport.ui

RESOURCES += \
    res.qrc
