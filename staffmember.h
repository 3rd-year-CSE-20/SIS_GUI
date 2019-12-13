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
    QString department;
    QVector<Course> courses;

public:
    StaffMember();
    StaffMember(QString first_name, QString last_name, QString gendre, QString picture, QString birth_date, QString address, QString college_id, QString degree, QString department);
    void setDegree(QString degree);
    QString getDegree();

    void setDepartment(QString department);
    QString getDepartment();

    QVector<Course> getCourses();
    void addCourse(QString course_name);
    void deleteCourse(QString course_name);
    bool save();

    static QVector<StaffMember> all();
    static StaffMember find(long long id);

    QVector<StaffMember> where(QString column, QString value);
    void delete1();

};

#endif // STAFFMEMBER_H
