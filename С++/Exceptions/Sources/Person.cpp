//
// Created by danpe on 08.11.2019.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "../Headers/Person.h"
#include "../Headers/InputError.h"

char *Person::getSurname() const {
    return this->surname;
}

void Person::setSurname(char *surname) {
    strcpy(this->surname, surname);
}

char *Person::getName() const {
    return this->name;
}

void Person::setName(char *name) {
    strcpy(this->name, name);
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
    rewind(stdin);
    char *buffer = InputError::inputString();
    strcpy(person.surname, buffer);
    buffer = InputError::inputString();
    strcpy(person.name, buffer);
    person.birthdayYear = InputError::input(0, 2019);
    return is;
}

void Person::table() {
    std::cout << std::setw(10) << "Surname" << "|"
              << std::setw(10) << "Name" << "|" << "B. Year|" << std::endl;
}