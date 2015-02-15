#-------------------------------------------------
#
# Project created by QtCreator 2015-02-14T11:12:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EDITOR
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    IrrRenderWidget.cpp \
    ParticleManager.cpp

HEADERS  += mainwindow.h \
    IrrRenderWidget.h \
    ParticleManager.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lIrrlicht
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lIrrlichtd

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
