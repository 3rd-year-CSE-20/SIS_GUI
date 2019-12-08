#ifndef PERSON_H
#define PERSON_H

#include <QString>


class Person
{
private:
    long long id;
    bool is_saved;
    QString first_name;
    QString last_name;
    QString gendre;
    QString picture;
    QString department;
    QString birth_date;
    QString address;

public:
    Person();
    Person(QString first_name, QString last_name, QString gendre, QString picture, QString department, QString address, QString birth_date);
    void setFirstName(QString first_name);
    QString getFirstName();
    void setLastName(QString last_name);
    QString getLastName();
    void setGendre(QString gendre);
    QString getGendre();
    void setPicture(QString picture);
    QString getPicture();
    void setDepartment(QString department);
    QString getDepartment();
    void setAddress(QString address);
    QString getAddress();
    void setBirthDate(QString birth_date);
    QString getBirthDate();
    void setId(long long id);
    long long getId();
    void setIsSaved(bool is_saved);
    bool isSaved();
};

#endif // PERSON_H
