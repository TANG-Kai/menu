#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T14:10:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = menu_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    orderitem.cpp

HEADERS  += mainwindow.h \
    orderitem.h \
    dish.h \
    ingredients.h \
    ingrenum.h

FORMS    += mainwindow.ui \
    orderitem.ui
