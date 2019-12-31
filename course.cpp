#include "course.h"
#include "globalDbObject.h"
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
    QSqlQuery query = SQLiteDb.sql_getQuery();

    QVector<Course> courses;
    Course temp;
    query.exec("SELECT * FROM courses");
    while(query.next()) {
        long long id = query.value(0).toLongLong();
        QString name = query.value(1).toString();


        temp.setId(id);
        temp.setName(name);
        temp.setIsSaved(true);
        courses.push_back(temp);
    }

    return courses;
}

Course Course::find(long long id) {
    QSqlQuery query = SQLiteDb.sql_getQuery();

    query.exec("SELECT * FROM courses WHERE id = " + QString::number(id));
    query.next();
    QString name = query.value(1).toString();
    Course course(name);
    course.setId(id);
    course.setIsSaved(true);

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

QVector<Course> Course::where(QString column, QString value){
    SQLiteDb.sql_select("*", "courses", column + " LIKE '" +  value +"%'");
    QSqlQuery query = SQLiteDb.sql_getQuery();
    QVector<Course> courses;
    while (query.next()) {
        int id = query.value(0).toInt();
        courses.push_back(find(id));
    }
    return courses;
}

QVector<Student> Course::getStudents(){
    SQLiteDb.sql_select("*", "courses_students", "course_id LIKE '" +  getName() +"%'");
    QSqlQuery query = SQLiteDb.sql_getQuery();
    QVector<Student> students;
    while (query.next()) {
        QString college_id = query.value(0).toString();
        students.push_back(Student::where("college_id",college_id)[0]);
    }
    return students;
}
