QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sticks
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    square.cpp \
    stick_class.cpp

HEADERS  += mainwindow.h \
    square.h \
    stick_class.h
