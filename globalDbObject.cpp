#include "globalDbObject.h"

SQLiteClass SQLiteDb = SQLiteClass("db.sqlite");
// students table
QString students_table = "students";
QStringList students_columns = {"id","first_name","last_name", "gendre", "picture",
                                "birth_date", "address", "college_id", "academic_year", "department"};
QStringList students_types = {"INTEGER PRIMARY KEY AUTOINCREMENT", "TEXT", "TEXT", "TEXT", "TEXT",
                              "TEXT", "TEXT", "TEXT", "TEXT", "TEXT"};

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
                                "birth_date", "address", "college_id", "degree", "department"};
QStringList staff_types = {"INTEGER PRIMARY KEY AUTOINCREMENT", "TEXT", "TEXT", "TEXT", "TEXT",
                              "TEXT", "TEXT", "TEXT", "TEXT", "TEXT"};

// courses  / students table
QString courses_staff_table = "courses_staff_members";
QStringList courses_staff_columns = {"course_id",  "staff_member_id"};
QStringList courses_staff_types = {"INTEGER", "INTEGER"};

// admins table
QString admins_table = "admins";
QStringList admins_columns = {"id","first_name","last_name", "gendre", "picture",
                                "birth_date", "address", "college_id"};
QStringList admins_types = {"INTEGER PRIMARY KEY AUTOINCREMENT", "TEXT", "TEXT", "TEXT", "TEXT",
                              "TEXT", "TEXT", "TEXT"};
