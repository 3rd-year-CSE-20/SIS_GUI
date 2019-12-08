#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include <QVector>
#include "course.h"

class Student : public Person
{
private:
    QString academic_year;
    QString college_id;
    QVector <Course> courses;
public:
    Student();
    Student(QString first_name, QString last_name, QString gendre, QString picture, QString department, QString address, QString birth_date,
            QString academic_year, QString college_id);
    void setAcademicYear(QString academic_year);
    QString getAcademicYear();
    void setCollegeId(QString college_id);
    QString getCollegeId();

    bool save();
    void delete1();
    QVector<Course> getCourses();
    void addCourse(QString course_name);
    void deleteCourse(QString course_name);
    static QVector<Student> all();
    static Student find(long long id);
    static QVector<Student> where(QString column, QString value);
};

#endif // STUDENT_H
