//
// Created by dan on 18.10.19.
//

#include <stdio_ext.h>
#include "../Headers/Person.h"

const std::string &Person::getSurname() const {
    return this->surname;
}

void Person::setSurname(const std::string &surname) {
    this->surname = surname;
}

const std::string &Person::getName() const {
    return this->name;
}

void Person::setName(const std::string &name) {
    this->name = name;
}

int Person::getBirthdayYear() const {
    return this->birthdayYear;
}

void Person::setBirthdayYear(int birthdayYear) {
    this->birthdayYear = birthdayYear;
}

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "surname: " << person.surname << std::endl << "name: " << person.name << std::endl
        << " birthdayYear: " << person.birthdayYear << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Person &person) {
    __fpurge(stdin);
    is >> person.surname;
    is >> person.name;
    is >> person.birthdayYear;
    return is;
}
