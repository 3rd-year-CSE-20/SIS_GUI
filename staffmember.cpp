#include "staffmember.h"
#include <QString>
#include "course.h"

/*static QString staff_members_table = "students";
static QStringList staff_members_columns = {"first_name","last_name", "gendre", "picture",
                                "birth_date", "address", "college_id", "degree", "department"};
*/
StaffMember::StaffMember() : Person() {
    this->degree = QString("");
    this->department = QString("");
    this->courses = QVector<Course>();
}

StaffMember::StaffMember(QString first_name, QString last_name, QString gendre, QString picture, QString birth_date, QString address, QString college_id, QString degree, QString department)
    : Person(first_name, last_name, gendre, picture, birth_date, address, college_id) {
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
        QString birth_date = query.value(5).toString();
        QString address = query.value(6).toString();
        QString college_id = query.value(7).toString();
        QString degree = query.value(8).toString();
        QString department = query.value(9).toString();

        StaffMember temp(first_name, last_name, gendre, picture, birth_date, address, college_id, degree, department);
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
    QString birth_date = query.value(5).toString();
    QString address = query.value(6).toString();
    QString college_id = query.value(7).toString();
    QString degree = query.value(8).toString();
    QString department = query.value(9).toString();

    StaffMember staff_member(first_name, last_name, gendre, picture, birth_date, address, college_id, degree, department);
    staff_member.setId(id);
    staff_member.setIsSaved(true);

    query1.exec("SELECT * FROM courses_staff_members WHERE course_id = " + QString::number(id));
    while(query1.next()) {
        staff_member.addCourse(Course::find(query1.value(1).toLongLong()).getName());
    }


    db.close();
    return staff_member;
}
