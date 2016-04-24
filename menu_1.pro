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
    orderitem.cpp \
    ingrenum.cpp \
    ingredients.cpp \
    dish.cpp \
    check.cpp \
    order.cpp \
    welcome.cpp \
    dishitem.cpp \
    linkedbuttons.cpp

HEADERS  += mainwindow.h \
    orderitem.h \
    dish.h \
    ingredients.h \
    ingrenum.h \
    check.h \
    order.h \
    welcome.h \
    dishitem.h \
    linkedbuttons.h \
    initiate.h

FORMS    += mainwindow.ui \
    orderitem.ui \
    check.ui \
    welcome.ui \
    dishitem.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    menu_1.pro.user \
    menu_1.pro.user.0e98341 \
    menu_1.pro.user.50c2ec4 \
    Screenshot from 2016-04-21 07-40-58.png \
    Screenshot from 2016-04-21 08-31-56.png
