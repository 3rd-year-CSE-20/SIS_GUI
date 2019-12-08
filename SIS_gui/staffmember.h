#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include <QString>
#include <QVector>
#include "person.h"
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

class StaffMember : public Person
{
private:
    QString degree;
    QVector<Course> courses;

public:
    StaffMember();
    StaffMember(QString first_name, QString last_name, QString gendre, QString picture, QString department, QString address, QString birth_date, QString degree);
    void setDegree(QString degree);
    QString getDegree();
    QVector<Course> getCourses();
    void addCourse(QString course_name);
    void deleteCourse(QString course_name);

    static QVector<StaffMember> all();
    static StaffMember find(long long id);
};

#endif // STAFFMEMBER_H
