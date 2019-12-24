#include "mainwindow.h"
#include "dashboard.h"
#include "backend.h"
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#define ELECTRICAL_DEPARTMENT 1
int main(int argc, char *argv[])
{
     databaseInitialization(); //uncomment if it is the first time to run the code
    QApplication a(argc, argv);
    Admin mariam ("Mariam", "Ali", "Female", "2","4/6/1998", " ",
            "1600001", "123");

    mariam.save();
    //qDebug()<<mariam.getCollegeId();
    MainWindow w;

    w.show();


//    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
//    QQmlApplicationEngine engine;
//    engine.load(QUrl::fromLocalFile("main.qml"));


    return a.exec();
}
