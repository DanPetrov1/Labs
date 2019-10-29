//
// Created by dan on 18.10.19.
//

#include <stdio_ext.h>
#include <iomanip>
#include "../Headers/Person.h"
#include "../Headers/InputError.h"

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
    os << std::setw(10) << person.surname << "|" << std::setw(10) << person.name
        << "|" << std::setw(7) << person.birthdayYear << "|";
    return os;
}

std::istream &operator>>(std::istream &is, Person &person) {
    __fpurge(stdin);
    is >> person.surname;
    is >> person.name;
    person.birthdayYear = InputError::input(0, 2019);
    return is;
}

void Person::table() {
    std::cout << std::setw(10) << "Surname" << "|"
            << std::setw(10) << "Name" << "|" << "B. Year|" << std::endl;
}