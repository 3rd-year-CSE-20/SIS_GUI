#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QVector>
#include "student.h"

class Course{

private:
    long long id;
    bool is_saved;
    QString name;

public:
    Course();
    Course(QString name);
    void setName(QString name);
    QString getName();
    void setId(long long id);
    long long getId();
    void setIsSaved(bool is_saved);
    bool isSaved();
    QVector<Student> getStudents()

    static QVector<Course> all();
    static Course find(long long id);
    static QVector<Course> where(QString column, QString value);
};

#endif // COURSE_H
