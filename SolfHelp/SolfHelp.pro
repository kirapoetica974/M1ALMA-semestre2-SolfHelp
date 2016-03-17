#-------------------------------------------------
#
# Project created by QtCreator 2016-03-16T16:10:18
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += svg
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SolfHelp
TEMPLATE = app


SOURCES += main.cpp\
        fenetre.cpp \
    accueil.cpp \
    jeulibre.cpp \
    clavierpiano.cpp \
    entrainementpage1.cpp \
    entrainementfacile.cpp \
    note.cpp \
    portee.cpp

HEADERS  += fenetre.h \
    accueil.h \
    jeulibre.h \
    clavierpiano.h \
    entrainementpage1.h \
    entrainementfacile.h \
    note.h \
    portee.h

RESOURCES += \
    image.qrc
