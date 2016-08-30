#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T23:39:01
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NPO
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11 -static

SOURCES += main.cpp\
    danbintreewidget.cpp \
    datetree.cpp \
    getdate.cpp \
    hotnewswidget.cpp \
    window.cpp \
    mytools.cpp

HEADERS  += \
    danbintreewidget.h \
    datetree.h \
    getdate.h \
    hotnewswidget.h \
    window.h \
    mytools.h

FORMS    += \
    MainWindow.ui \
    DialogQuit.ui

DISTFILES +=

RESOURCES += \
    data.qrc \
    MainWindow.qrc
