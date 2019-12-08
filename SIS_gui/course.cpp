#include "course.h"
#include <QString>
#include <QVector>

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


Course::Course() {
    this->id = 0;
    this->is_saved = false;
    this->name = QString("");
}

Course::Course(QString name) {
    this->id = 0;
    this->is_saved = false;
    this->name = name;
}

void Course::setName(QString name) {
    this->name = name;
}

QString Course::getName() {
    return this->name;
}

QVector<Course> Course::all() {
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


    QVector<Course> courses;
    Course temp;
    query.exec("SELECT * FROM courses");
    while(query.next()) {
        long long id = query.value(0).toLongLong();
        QString name = query.value(1).toString();


        temp.setId(id);
        temp.setIsSaved(true);
        courses.push_back(temp);
    }


    db.close();
    return courses;
}

Course Course::find(long long id) {
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


    query.exec("SELECT * FROM courses WHERE id = " + QString::number(id));
    query.next();
    QString name = query.value(1).toString();
    Course course(name);
    course.setId(id);
    course.setIsSaved(true);

    db.close();
    return course;
}

void Course::setId(long long id) {
    this->id = id;
}

long long Course::getId() {
    return this->id;
}

void Course::setIsSaved(bool is_saved) {
    this->is_saved = is_saved;
}

bool Course::isSaved() {
    return this->is_saved;
}
