#-------------------------------------------------
#
# Project created by QtCreator 2016-07-14T14:56:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo_pressure
TEMPLATE = app


SOURCES += main.cpp\
        canvas.cpp \
    pressuremap.cpp

HEADERS  += canvas.h \
    pressuremap.h

FORMS    += canvas.ui
