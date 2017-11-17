#-------------------------------------------------
#
# Project created by QtCreator 2017-09-09T11:53:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rent
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    product.cpp \
    databaseproduct.cpp \
    productcard.cpp \
    catalogwidget.cpp \
    basketcard.cpp \
    basketwidget.cpp \
    statuscard.cpp \
    statuswidget.cpp \
    order.cpp

HEADERS  += mainwindow.h \
    product.h \
    databaseproduct.h \
    productcard.h \
    catalogwidget.h \
    basketcard.h \
    basketwidget.h \
    statuscard.h \
    statuswidget.h \
    order.h

FORMS    += mainwindow.ui
