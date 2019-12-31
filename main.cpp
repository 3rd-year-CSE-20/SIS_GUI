#include "mainwindow.h"
#include "dashboard.h"
#include "backend.h"
#include "login.h"
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#define ELECTRICAL_DEPARTMENT 1
int main(int argc, char *argv[]){
//    databaseInitialization(); //uncomment if it is the first time to run the code
    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();
    return a.exec();
}
