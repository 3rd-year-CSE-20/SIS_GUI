#include "staffmember.h"
#include "sqliteclass.h"
#include "globalDbObject.h"
#include "student.h"

static QString students_table = "students";
static QStringList students_columns = {"first_name","last_name", "gendre", "picture",
                                "birth_date", "address", "college_id", "password", "academic_year", "department", "GPA"};

Student::Student() : Person()
{
    this->academic_year = "0";
    this->department = "";
}

Student::Student(QString first_name, QString last_name, QString gendre, QString picture, QString birth_date, QString address, QString college_id, QString password,
                 QString academic_year, QString department) : Person(first_name, last_name, gendre, picture, birth_date, address, college_id, password) {
    this-> academic_year = academic_year;
    this->department = department;
}

void Student::setAcademicYear(QString academic_year){
    this->academic_year = academic_year;
}

void Student::setDepartment(QString department) {
    this->department = department;
}

QString Student::getDepartment() {
    return this->department;
}

QString Student::getAcademicYear(){
    return this-> academic_year;
}

QVector<Course> Student::getCourses() {
    return this->courses;
}

void Student::setGPA(QString GPA) {
    this->GPA = GPA;
}

QString Student::getGPA() {
    return this->GPA;
}

void Student::addCourse(QString course_name) {
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

void Student::deleteCourse(QString course_name) {
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

QVector<Student> Student::all() {
    QSqlQuery query = SQLiteDb.sql_getQuery();

    QVector<Student> students;


    query.exec("SELECT * FROM students");
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
        QString academic_year = query.value(9).toString();
        QString department = query.value(10).toString();
        QString GPA = query.value(11).toString();

        Student temp(first_name, last_name, gendre, picture, birth_date, address, college_id, password, academic_year, department);
        temp.setId(id);
        temp.setGPA(GPA);
        temp.setIsSaved(true);

        query.exec("SELECT * FROM courses_students WHERE course_id = " + QString::number(id));
        while(query.next()) {
            temp.addCourse(Course::find(query.value(1).toLongLong()).getName());
        }
        students.push_back(temp);
    }

    return students;
}

bool Student::isInDatabase(long long id) {
    QSqlQuery query = SQLiteDb.sql_getQuery();

    query.exec("SELECT * FROM students WHERE id = " + QString::number(id));
    if(query.next()) {
        return true;
    }

    return false;
}

bool Student::save(){
    QString id_ = QString::number(getId());
    qDebug() << "id : " << id_;
    SQLiteDb.sql_select("*", students_table, " id = " + id_);
    QSqlQuery query = SQLiteDb.sql_getQuery();
    QStringList values = {getFirstName(),  getLastName(), getGendre(), getPicture(),
                          getBirthDate(), getAddress(), getCollegeId(), getPassword(), getAcademicYear(),  getDepartment(), getGPA()};
    if(query.next()){
        SQLiteDb.sql_update(students_table, students_columns, values, "id = " + id_);

        for(int i = 0; i < courses.size(); i++){
            QString course_name = courses[i].getName();
//        SQLiteDb.sql_select("*", "courses_students", " student_id = " + id_ + " AND course_id " + course_id);
//        query = SQLiteDb.sql_getQuery();
//        if(!query.next()){
            SQLiteDb.sql_insert("courses_students", {"student_id", "course_id"}, {getCollegeId(), course_name});
//        }
        }
        return true;
    }
    SQLiteDb.sql_insert(students_table, students_columns, values);
    for(int i = 0; i < courses.size(); i++){
        QString course_name = courses[i].getName();
        SQLiteDb.sql_insert("courses_students", {"student_id", "course_id"}, {getCollegeId(),course_name});
    }
    return false;
}

void Student::delete1(){
    QString student_id = QString::number(getId());
    SQLiteDb.sql_delete(students_table, "id = " + student_id);
    SQLiteDb.sql_delete("courses_students", "student_id = " + student_id);
}

Student Student::find(long long id) {
    QSqlQuery query = SQLiteDb.sql_getQuery();

    query.exec("SELECT * FROM students WHERE id = " + QString::number(id));

    query.next();
    QString first_name = query.value(1).toString();
    QString last_name = query.value(2).toString();
    QString gendre = query.value(3).toString();
    QString picture = query.value(4).toString();
    QString birth_date = query.value(5).toString();
    QString address = query.value(6).toString();
    QString college_id = query.value(7).toString();
    QString password = query.value(8).toString();
    QString academic_year = query.value(9).toString();
    QString department = query.value(10).toString();
    QString GPA = query.value(11).toString();

    Student student(first_name, last_name, gendre, picture, birth_date, address, college_id, password, academic_year, department);
    student.setId(id);
    student.setGPA(GPA);
    student.setIsSaved(true);

    query.exec("SELECT * FROM courses_students WHERE student_id = " + college_id);
    while(query.next()) {
        student.addCourse(query.value(0).toString());
    }

    return student;
}

QVector<Student> Student::where(QString column, QString value){
    SQLiteDb.sql_select("*", students_table, column + " LIKE '" +  value +"%'");
    QSqlQuery query = SQLiteDb.sql_getQuery();
    QVector<Student> students;
    while (query.next()) {
        int id = query.value(0).toInt();
        students.push_back(find(id));
    }
    return students;
}

int Student::getLastId(){
    QSqlQuery query = SQLiteDb.sql_getQuery();
    query.exec("SELECT id FROM students ORDER BY id DESC LIMIT 0, 1;");
    if(query.next()){
        return query.value(0).toInt();
    }else{
        return 0;
    }
}

QVector<Student> Student::getByCourse(QString courseName){
    SQLiteDb.sql_select("*", "courses_students", "course_id LIKE '" + courseName + "%'");
    QSqlQuery query = SQLiteDb.sql_getQuery();
    QVector<Student> students;
    while (query.next()) {
        QString college_id = query.value(1).toString();
        QVector<Student> studentsVec = Student::where("college_id",college_id);

        if(studentsVec.length()>0){
            students.push_back(studentsVec[0]);
        }
    }
    qDebug() << "length in student is " << students.length();
    return students;
}
