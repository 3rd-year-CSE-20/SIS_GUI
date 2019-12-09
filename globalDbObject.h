#ifndef SQLITEDB_H
#define SQLITEDB_H
#include "sqliteclass.h"
#include <QString>
#include <QStringList>
extern SQLiteClass SQLiteDb;

extern QString students_table;
extern QStringList students_columns;
extern QStringList students_types;

extern QString courses_table;
extern QStringList courses_columns;
extern QStringList courses_types;

extern QString courses_students_table;
extern QStringList courses_students_columns;
extern QStringList courses_students_types;

extern QString staff_table;
extern QStringList staff_columns;
extern QStringList staff_types;

extern QString courses_staff_table;
extern QStringList courses_staff_columns;
extern QStringList courses_staff_types;

extern QString admins_table;
extern QStringList admins_columns;
extern QStringList admins_types;
#endif // SQLITEDB_H
