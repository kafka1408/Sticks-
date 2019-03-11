QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = Sticks
TEMPLATE = app


SOURCES += main.cpp\
           square.cpp \
           stick_class.cpp

HEADERS  += square.h \
            stick_class.h
