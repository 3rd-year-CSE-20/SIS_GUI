#include "mainwindow.h"
#include "dashboard.h"
#include "backend.h"
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#define ELECTRICAL_DEPARTMENT 1
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   // databaseInitialization();
Student mariam;
mariam.setFirstName("Mariam");
mariam.setPassword("123");
mariam.setCollegeId("1601374");
mariam.setIsSaved(true);
qDebug()<<mariam.getCollegeId();
    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    QQmlApplicationEngine engine;
//     engine.load(QUrl::fromLocalFile("main.qml"));


    return a.exec();
}
