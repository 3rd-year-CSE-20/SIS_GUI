#include "sqliteclass.h"
#include "globalDbObject.h"

SQLiteClass::SQLiteClass(QString dbName)
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    QString dbPath = QDir::currentPath();

    dbPath += "/" + dbName;

    qDebug() << dbPath;

    db.setDatabaseName(dbPath);

    if(!db.open()){
        qDebug() << "Problem while opening the database";
    }

    QSqlQuery qry;
    query = qry;
}

int SQLiteClass::sql_create(QString table, QStringList columns, QStringList types){
    QString sql = QString("CREATE TABLE ") + table + "(";
    QString temp = "";

    int size = columns.size();
    for(int i = 0; i < size; i++){
        temp += columns.at(i) + " " + types.at(i) + ",";
    }
    temp.chop(1);

    sql += temp + ");";

    qDebug() << sql;

    if(!query.exec(sql)){
        qDebug() << "error while creating";
    }

    return 0;
}


int SQLiteClass::sql_select(QString select, QString from, QString where){
    QString sql = QString("SELECT ") + select + QString(" FROM ") + from;
    if(where == ""){
        sql += QString(";");
    }
    else{
         sql += QString(" WHERE ") + where + QString(";");
    }
    qDebug() << sql;

    if(!query.exec(sql)){
        qDebug() << "error while selecting";
    }

    return 0;
}

int SQLiteClass::sql_insert(QString table, QStringList columns, QStringList values){
    QString sql = QString("INSERT INTO ") + table + QString(" ( ");
    QString co = "";
    QString vl = "";
    int size = columns.size();
    for(int i = 0; i < size; i++){
        co += QString("`") + columns.at(i) + QString("`") + QString(",");
        vl += QString("'") + values.at(i) + QString("'") + QString(",");
        //vl += "?,";
        //query.addBindValue(values.at(i));
    }

    co.chop(1);
    vl.chop(1);


    sql += co + QString(") ") + QString("VALUES(") + vl + QString(");");

    qDebug() << sql;

    if(!query.exec(sql)){
        qDebug() << "error while inserting";
    }

    return query.numRowsAffected();
}

int SQLiteClass::sql_update(QString table, QStringList columns, QStringList values, QString where){

    QString sql = QString("UPDATE `") + table + QString("` SET ")  ;
    QString temp = "";

    int size = columns.size();
    for(int i = 0; i < size; i++){
        temp = temp + QString("`") + columns.at(i) + QString("`") + QString("=") + "'" + values.at(i) + "'" + QString(",");
        //query.addBindValue(values.at(i));
    }

    temp.chop(1);
    sql = sql + temp + QString(" WHERE ") + where;
    //qDebug() << sql;


    if(!query.exec(sql)){
        qDebug() << "error while updating";
    }
    return query.numRowsAffected();
}


int SQLiteClass::sql_delete(QString table, QString where){
    QString sql = QString("DELETE ") + QString("FROM ") + table + QString(" WHERE ") + where ;
    //qDebug() << sql;
    QSqlQuery qry;
    qry.exec(sql);
    query = qry;
    return 0;
}

int SQLiteClass::sql_print(){
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int department = query.value(2).toInt();
        qDebug() << id << name << department;
    }
    return 0;
}

QSqlQuery SQLiteClass::sql_getQuery(){
    return query;
}


int SQLiteClass::sql_close(){
    db.close();
    return 0;
}

void databaseInitialization(){
    // students table
    QString students_table = "students";
    QStringList students_columns = {"id","first_name","last_name", "gendre", "picture",
                                    "birth_date", "address", "college_id", "password", "academic_year", "department", "GPA"};
    QStringList students_types = {"INTEGER PRIMARY KEY AUTOINCREMENT", "TEXT", "TEXT", "TEXT", "TEXT",
                                  "TEXT", "TEXT", "TEXT", "TEXT", "TEXT", "TEXT", "TEXT"};

    // courses table
    QString courses_table = "courses";
    QStringList courses_columns = {"id","name"};
    QStringList courses_types = {"INTEGER PRIMARY KEY AUTOINCREMENT", "TEXT"};

    // courses  / students table
    QString courses_students_table = "courses_students";
    QStringList courses_students_columns = {"course_id",  "student_id"};
    QStringList courses_students_types = {"INTEGER", "INTEGER"};

    // staff members table
    QString staff_table = "staff_members";
    QStringList staff_columns = {"id","first_name","last_name", "gendre", "picture",
                                    "birth_date", "address", "college_id", "password", "degree", "department"};
    QStringList staff_types = {"INTEGER PRIMARY KEY AUTOINCREMENT", "TEXT", "TEXT", "TEXT", "TEXT",
                                  "TEXT", "TEXT", "TEXT", "TEXT", "TEXT", "TEXT"};

    // courses  / staff members table
    QString courses_staff_table = "courses_staff_members";
    QStringList courses_staff_columns = {"course_id",  "staff_member_id"};
    QStringList courses_staff_types = {"INTEGER", "INTEGER"};

    // admins table
    QString admins_table = "admins";
    QStringList admins_columns = {"id","first_name","last_name", "gendre", "picture",
                                    "birth_date", "address", "college_id", "password"};
    QStringList admins_types = {"INTEGER PRIMARY KEY AUTOINCREMENT", "TEXT", "TEXT", "TEXT", "TEXT",
                                  "TEXT", "TEXT", "TEXT", "TEXT"};

    // creating tables
    SQLiteDb.sql_create(students_table, students_columns, students_types);
    SQLiteDb.sql_create(courses_table, courses_columns, courses_types);
    SQLiteDb.sql_create(courses_students_table, courses_students_columns, courses_students_types);
    SQLiteDb.sql_create(staff_table, staff_columns, staff_types);
    SQLiteDb.sql_create(courses_staff_table, courses_staff_columns, courses_staff_types);
    SQLiteDb.sql_create(admins_table, admins_columns, admins_types);
}








