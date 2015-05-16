#-------------------------------------------------
#
# Project created by QtCreator 2015-01-23T20:00:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dialog
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    subdialog.cpp

HEADERS  += mainwindow.h \
    ui_mainwindow.h \
    subdialog.h

FORMS    += mainwindow.ui \
    subdialog.ui
