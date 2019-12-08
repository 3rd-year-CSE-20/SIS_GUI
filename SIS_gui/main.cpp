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
    databaseInitialization();

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    QQmlApplicationEngine engine;
//     engine.load(QUrl::fromLocalFile("main.qml"));


    return a.exec();
}
