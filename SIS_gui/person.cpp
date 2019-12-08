#include "person.h"
#include <QString>

Person::Person()
{
    this->id = 0;
    this->is_saved = false;
    this->first_name = QString("");
    this->last_name = QString("");
    this->gendre = QString("");
    this->picture = QString("");
    this->department = QString("");
    this->birth_date = QString("");
    this->address = QString("");
}

Person::Person(QString first_name, QString last_name, QString gendre, QString picture, QString department, QString address, QString birth_date) {
    this->id = 0;
    this->is_saved = false;
    this->first_name = first_name;
    this->last_name = last_name;
    this->gendre = gendre;
    this->picture = picture;
    this->department = department;
    this->birth_date = birth_date;
    this->address = address;
}

void Person::setFirstName(QString first_name) {
    this->first_name = first_name;
}

QString Person::getFirstName() {
    return this->first_name;
}

void Person::setLastName(QString last_name) {
    this->last_name = last_name;
}

QString Person::getLastName() {
    return this->last_name;
}

void Person::setGendre(QString gendre) {
    this->gendre = gendre;
}

QString Person::getGendre() {
    return this->gendre;
}

void Person::setPicture(QString picture) {
    this->picture = picture;
}

QString Person::getPicture() {
    return this->picture;
}

void Person::setDepartment(QString department) {
    this->department = department;
}

QString Person::getDepartment() {
    return this->department;
}

void Person::setAddress(QString address) {
    this->address = address;
}

QString Person::getAddress() {
    return this->address;
}

void Person::setBirthDate(QString birth_date) {
    this->birth_date = birth_date;
}

QString Person::getBirthDate() {
    return this->birth_date;
}

void Person::setId(long long id) {
    this->id = id;
}

long long Person::getId() {
    return this->id;
}

void Person::setIsSaved(bool is_saved) {
    this->is_saved = is_saved;
}

bool Person::isSaved() {
    return this->is_saved;
}
