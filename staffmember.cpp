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
#include <globalDbObject.h>

static QString staff_table = "staff_members";
static QStringList staff_columns = {"first_name","last_name", "degree", "birth_date",
                                "gendre", "address", "password", "picture", "degree", "department"};
static QStringList staff_types = {"INTEGER PRIMARY KEY AUTOINCREMENT", "TEXT", "TEXT", "TEXT", "TEXT",
                              "TEXT", "TEXT", "TEXT", "TEXT", "TEXT", "TEXT"};

StaffMember::StaffMember() : Person() {
    this->degree = QString("");
    this->department = QString("");
    this->courses = QVector<Course>();
}

StaffMember::StaffMember(QString first_name, QString last_name, QString gendre, QString picture, QString birth_date, QString address, QString college_id, QString password, QString degree, QString department)
    : Person(first_name, last_name, gendre, picture, birth_date, address, college_id, password) {
    this->degree = degree;
    this->department = department;
    this->courses = QVector<Course>();
}

void StaffMember::setDegree(QString degree) {
    this->degree = degree;
}

QString StaffMember::getDegree() {
    return this->degree;
}

void StaffMember::setDepartment(QString department) {
    this->department = department;
}

QString StaffMember::getDepartment() {
    return this->department;
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
    QSqlQuery query = SQLiteDb.sql_getQuery();

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
        QString birth_date = query.value(5).toString();
        QString address = query.value(6).toString();
        QString college_id = query.value(7).toString();
        QString password = query.value(8).toString();
        QString degree = query.value(9).toString();
        QString department = query.value(10).toString();

        StaffMember temp(first_name, last_name, gendre, picture, birth_date, address, college_id, password, degree, department);
        temp.setId(id);
        temp.setIsSaved(true);

        query1.exec("SELECT * FROM courses_staff_members WHERE course_id = " + QString::number(id));
        while(query1.next()) {
            temp.addCourse(Course::find(query1.value(1).toLongLong()).getName());
        }
        staff_members.push_back(temp);
    }

    return staff_members;
}

bool StaffMember::isInDatabase(long long id) {
    QSqlQuery query = SQLiteDb.sql_getQuery();

    query.exec("SELECT * FROM staff_members WHERE id = " + QString::number(id));
    if(query.next()) {
        return true;
    }

    return false;
}

StaffMember StaffMember::find(long long id) {
    QSqlQuery query = SQLiteDb.sql_getQuery();

    query.exec("SELECT * FROM staff_members WHERE id = " + QString::number(id));
    QSqlQuery query1;
    query.next();
    QString first_name = query.value(1).toString();
    QString last_name = query.value(2).toString();
    QString gendre = query.value(3).toString();
    QString picture = query.value(4).toString();
    QString birth_date = query.value(5).toString();
    QString address = query.value(6).toString();
    QString college_id = query.value(7).toString();
    QString password = query.value(8).toString();
    QString degree = query.value(9).toString();
    QString department = query.value(10).toString();

    StaffMember staff_member(first_name, last_name, gendre, picture, birth_date, address, college_id, password, degree, department);
    staff_member.setId(id);
    staff_member.setIsSaved(true);

    query1.exec("SELECT * FROM courses_staff_members WHERE course_id = " + QString::number(id));
    while(query1.next()) {
        staff_member.addCourse(Course::find(query1.value(1).toLongLong()).getName());
    }

    return staff_member;
}

bool StaffMember::save(){
    QString id_ = QString::number(getId());
    SQLiteDb.sql_select("*", staff_table, " id = " + id_);
    QSqlQuery query = SQLiteDb.sql_getQuery();
    QStringList values = {getFirstName(),  getLastName(), getDegree(), getBirthDate(),
                          getGendre(), getAddress(), getPassword(), getPicture(), getDegree(),  getDepartment()};
    if(query.next()){
        SQLiteDb.sql_update(staff_table, staff_columns, values, "id = " + id_);

        for(int i = 0; i < courses.size(); i++){
            QString course_id = QString::number(courses[i].getId());
            SQLiteDb.sql_select("*", "courses_staff_members", " staff_member_id = " + id_ + " AND course_id " + course_id);
            query = SQLiteDb.sql_getQuery();
            if(!query.next()){
                SQLiteDb.sql_insert("courses_staff_members", {"staff_member_id", "courses_id"}, {id_, course_id});
            }
        }
        return true;
    }
    SQLiteDb.sql_insert(staff_table, staff_columns, values);
    for(int i = 0; i < courses.size(); i++){
        QString course_id = QString::number(courses[i].getId());
        SQLiteDb.sql_insert("courses_staff_members", {"staff_member_id", "course_id"}, {id_, course_id});
    }
    return false;
}

QVector<StaffMember> StaffMember::where(QString column, QString value){
    SQLiteDb.sql_select("*", staff_table, column + " = " +  value);
    QSqlQuery query = SQLiteDb.sql_getQuery();
    QVector<StaffMember> staff_members;
    while (query.next()) {
        int id = query.value(0).toInt();
        staff_members.push_back(find(id));
    }
    return staff_members;
}

void StaffMember::delete1(){
    QString staff_id = QString::number(getId());
    SQLiteDb.sql_delete(staff_table, "id = " + staff_id);
    SQLiteDb.sql_delete("courses_staff_members", "staff_member_id = " + staff_id);
}


