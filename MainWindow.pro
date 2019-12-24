#-------------------------------------------------
#
# Project created by QtCreator 2019-12-08T23:52:08
#
#-------------------------------------------------

QT       += core gui
QT        += qml quick
QT += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindow
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        admin.cpp \
        backend.cpp \
        clickablelabel.cpp \
        course.cpp \
        dashboard.cpp \
        globalDbObject.cpp \
        login.cpp \
        main.cpp \
        mainwindow.cpp \
        person.cpp \
        register.cpp \
        sqliteclass.cpp \
        staffmember.cpp \
        student.cpp

HEADERS += \
        admin.h \
        backend.h \
        clickablelabel.h \
        course.h \
        dashboard.h \
        globalDbObject.h \
        login.h \
        mainwindow.h \
        person.h \
        register.h \
        sqliteclass.h \
        staffmember.h \
        student.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    theme.css
