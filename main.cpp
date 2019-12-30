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
//    databaseInitialization(); //uncomment if it is the first time to run the code
    QApplication a(argc, argv);
//    Admin aa;
//    aa.setPassword("0");
//    aa.setCollegeId("900001");
//    aa.save();
//    StaffMember mariam;
//    mariam.setFirstName("Trial");
//    mariam.setId(2);
//    mariam.save();
//    qDebug()<<"is saved";
//    mariam.delete1();
//    qDebug()<<"is deleted";
    //qDebug()<<mariam.getCollegeId();
//    qDebug() << "length" << Admin::where("college_id","1601146").length();
//    Login l;
//    l.show();

//    Student s("fname","lname","male","pic is here","birth","addr","1601146","00","4747","department");
//    s.save();

    MainWindow w;

//    a.setStyleSheet(/);

    w.show();
//    Student s;
//    s.setLastName("hhhhh");
//    StaffMember ss;
//    ss.setLastName("sdsdsd");
//    ss.save();
/*    QFile css("../SIS_GUI/theme.css");
    css.open(QFile::ReadOnly);
    QString Styles = css.readAll();
    a.setStyleSheet(Styles)*/;

//    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
//    QQmlApplicationEngine engine;
//    engine.load(QUrl::fromLocalFile("main.qml"));


    return a.exec();
}
