#-------------------------------------------------
#
# Project created by QtCreator 2014-07-02T00:49:05
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Recognitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    auth.cpp \
    adminscreen.cpp \
    windowmanager.cpp \
    userscreen.cpp \
    exuserscreen.cpp \
    goodsmgmtscreen.cpp \
    cvtoqt.cpp \
    cameracapture.cpp \
    packet.cpp

HEADERS  += mainwindow.h \
    auth.h \
    adminscreen.h \
    windowmanager.h \
    userscreen.h \
    exuserscreen.h \
    goodsmgmtscreen.h \
    cvtoqt.h \
    cameracapture.h \
    packet.h

FORMS    += mainwindow.ui \
    adminscreen.ui \
    userscreen.ui \
    exuserscreen.ui \
    goodsmgmtscreen.ui
INCLUDEPATH += "/usr/local/include/opencv" \
               "/usr/local/include"
LIBS += `pkg-config --libs opencv`
