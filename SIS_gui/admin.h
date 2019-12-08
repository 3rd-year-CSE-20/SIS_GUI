#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include <QVector>
#include "course.h"

class Admin : public Person
{
public:
    Admin();
    Admin(QString first_name, QString last_name, QString gendre, QString picture, QString birth_date, QString address,
            QString college_id);
    void setAcademicYear(QString academic_year);
    QString getAcademicYear();
    void setDepartment(QString department);
    QString getDepartment();

    bool save();
    void delete1();
    static QVector<Admin> all();
    static Admin find(long long id);
    static QVector<Admin> where(QString column, QString value);
};

#endif // ADMIN_H
