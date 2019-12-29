#include "mainwindow.h"
#include "dashboard.h"
#include "backend.h"
#include "login.h"
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#define ELECTRICAL_DEPARTMENT 1
int main(int argc, char *argv[])
{
    //databaseInitialization(); //uncomment if it is the first time to run the code
    QApplication a(argc, argv);
//    StaffMember mariam;
//    mariam.setFirstName("mariam");
//    mariam.setId(1);
//    mariam.setPassword("0");
//    mariam.setCollegeId("1601146");
//    mariam.save();
//    mariam.delete1();
    //qDebug()<<mariam.getCollegeId();
//    qDebug() << "length" << Admin::where("college_id","1601146").length();
//    Login l;
//    l.show();

//    Student s("fname","lname","male","pic is here","birth","addr","1601146","00","4747","department");
//    s.save();

    MainWindow w;

//    a.setStyleSheet(/);

    w.show();
/*    QFile css("../SIS_GUI/theme.css");
    css.open(QFile::ReadOnly);
    QString Styles = css.readAll();
    a.setStyleSheet(Styles)*/;

//    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
//    QQmlApplicationEngine engine;
//    engine.load(QUrl::fromLocalFile("main.qml"));


    return a.exec();
}
