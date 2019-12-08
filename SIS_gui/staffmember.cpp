#include "staffmember.h"
#include <QString>
#include "course.h"

#include <QSqlDatabase>
#include <QSql>
#include <QSqlError>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <QStringList>
#include <QSqlError>

StaffMember::StaffMember() : Person() {
    this->degree = QString("");
    this->courses = QVector<Course>();
}

StaffMember::StaffMember(QString first_name, QString last_name, QString gendre, QString picture, QString department, QString address, QString birth_date, QString degree)
    : Person(first_name, last_name, gendre, picture, department, address, birth_date) {
    this->degree = degree;
    this->courses = QVector<Course>();
}

void StaffMember::setDegree(QString degree) {
    this->degree = degree;
}

QString StaffMember::getDegree() {
    return this->degree;
}


QVector<Course> StaffMember::getCourses() {
    return this->courses;
}

void StaffMember::addCourse(QString course_name) {
    int index = -1;
    for(int i = 0; i < this->courses.size(); i++) {
        if(this->courses[0].getName() == course_name) {
            index = i;
            break;
        }
    }
    if(index == -1)
        this->courses.push_back(Course(course_name));
}

void StaffMember::deleteCourse(QString course_name) {
    int index = -1;
    for(int i = 0; i < this->courses.size(); i++) {
        if(this->courses[0].getName() == course_name) {
            index = i;
            break;
        }
    }
    if(index != -1)
        this->courses.remove(index);
}

QVector<StaffMember> StaffMember::all() {
    QSqlQuery query;
    QSqlDatabase db;

    db = QSqlDatabase::addDatabase("QSQLITE");

    QString dbPath = QDir::currentPath();

    dbPath += "/" + QString("db.sqlite");

    qDebug() << dbPath;

    db.setDatabaseName(dbPath);

    if(!db.open()){
        qDebug() << "Problem while opening the database";
    }


    QVector<StaffMember> staff_members;
    StaffMember temp;
    query.exec("SELECT * FROM staff_members");
    QSqlQuery query1;
    while(query.next()) {
        long long id = query.value(0).toLongLong();
        QString first_name = query.value(1).toString();
        QString last_name = query.value(2).toString();
        QString gendre = query.value(3).toString();
        QString picture = query.value(4).toString();
        QString department = query.value(5).toString();
        QString birth_date = query.value(6).toString();
        QString address = query.value(7).toString();
        QString degree = query.value(8).toString();

        StaffMember temp(first_name, last_name, gendre, picture, department, birth_date, address, degree);
        temp.setId(id);
        temp.setIsSaved(true);

        query1.exec("SELECT * FROM courses_staff_members WHERE course_id = " + QString::number(id));
        while(query1.next()) {
            temp.addCourse(Course::find(query1.value(1).toLongLong()).getName());
        }
        staff_members.push_back(temp);
    }


    db.close();
    return staff_members;
}

StaffMember StaffMember::find(long long id) {
    QSqlQuery query;
    QSqlDatabase db;

    db = QSqlDatabase::addDatabase("QSQLITE");

    QString dbPath = QDir::currentPath();

    dbPath += "/" + QString("db.sqlite");

    qDebug() << dbPath;

    db.setDatabaseName(dbPath);

    if(!db.open()){
        qDebug() << "Problem while opening the database";
    }

    query.exec("SELECT * FROM staff_members");
    QSqlQuery query1;
    query.next();
    QString first_name = query.value(1).toString();
    QString last_name = query.value(2).toString();
    QString gendre = query.value(3).toString();
    QString picture = query.value(4).toString();
    QString department = query.value(5).toString();
    QString birth_date = query.value(6).toString();
    QString address = query.value(7).toString();
    QString degree = query.value(8).toString();

    StaffMember staff_member(first_name, last_name, gendre, picture, department, birth_date, address, degree);
    staff_member.setId(id);
    staff_member.setIsSaved(true);

    query1.exec("SELECT * FROM courses_staff_members WHERE course_id = " + QString::number(id));
    while(query1.next()) {
        staff_member.addCourse(Course::find(query1.value(1).toLongLong()).getName());
    }


    db.close();
    return staff_member;
}
