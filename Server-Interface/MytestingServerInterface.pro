#-------------------------------------------------
#
# Project created by QtCreator 2018-05-05T15:48:13
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MytestingServerInterface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mythread.cpp \
    patient.cpp \
    user.cpp \
    nursepatient.cpp

HEADERS  += mainwindow.h \
    mythread.h \
    patient.h \
    user.h \
    nursepatient.h

FORMS    += mainwindow.ui

DISTFILES += \
    users.csv \
    patients.csv \
    nursePatient.csv \
    update.png \
    right.png \
    left.png
