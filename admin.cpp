#include "admin.h"
#include "sqliteclass.h"
#include "globalDbObject.h"

static QString admins_table = "admins";
static QStringList admins_columns = {"first_name","last_name", "gendre", "picture",
                                "birth_date", "address", "college_id", "password"};

Admin::Admin() : Person()
{
}

Admin::Admin(QString first_name, QString last_name, QString gendre, QString picture, QString birth_date, QString address, QString college_id, QString password)
    : Person(first_name, last_name, gendre, picture, birth_date, address, college_id, password)
{
}

QVector<Admin> Admin::all() {
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


    QVector<Admin> admins;
    Admin temp;
    query.exec("SELECT * FROM admins");
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


        Admin temp(first_name, last_name, gendre, picture, birth_date, address, college_id, password);
        temp.setId(id);
        temp.setIsSaved(true);
        admins.push_back(temp);
    }


    db.close();
    return admins;
}

bool Admin::save(){
    QString id_ = QString::number(getId());
    SQLiteDb.sql_select("*", admins_table, " id = " + id_);
    QSqlQuery query = SQLiteDb.sql_getQuery();
    QStringList values = {getFirstName(),  getLastName(), getGendre(), getPicture(),
                          getBirthDate(), getAddress(), getCollegeId(), getPassword()};
    if(query.next()){
        SQLiteDb.sql_update(admins_table, admins_columns, values, "id = " + id_);
        return true;
    }
    SQLiteDb.sql_insert(admins_table, admins_columns, values);
    return false;
}

bool Admin::isInDatabase(long long id) {
    QSqlQuery query = SQLiteDb.sql_getQuery();
    query.exec("SELECT * FROM admins WHERE id = " + QString::number(id));
    if(query.next()) {
        return true;
    }
    return false;
}

void Admin::delete1(){
    SQLiteDb.sql_delete(admins_table, "id = " + QString::number(getId()));
}

Admin Admin::find(long long id) {
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

    query.exec("SELECT * FROM admins WHERE id = " + QString::number(id));
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

    Admin admin(first_name, last_name, gendre, picture, birth_date, address, college_id, password);
    admin.setId(id);
    admin.setIsSaved(true);

    db.close();
    return admin;
}

QVector<Admin> Admin::where(QString column, QString value){
    SQLiteDb.sql_select("*", admins_table, column + " = " +  value);
    QSqlQuery query = SQLiteDb.sql_getQuery();
    QVector<Admin> admins;
    while (query.next()) {
        int id = query.value(0).toInt();
        admins.push_back(find(id));
    }
    return admins;
}





