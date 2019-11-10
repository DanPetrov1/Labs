//
// Created by danpe on 08.11.2019.
//
#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/Tourist.h"
#include "../Headers/InputError.h"
#include "../Headers/MemoryError.h"
#include <iomanip>

Tourist::Tourist(char *surname, char *name, int birthdayYear,
                 int passportNumber) : Person(surname, name, birthdayYear){
    this->borderSize = 0;
    this->border = nullptr;
}

int Tourist::getPassportNumber() const {
    return passportNumber;
}

void Tourist::setPassportNumber(int passportNumber) {
    Tourist::passportNumber = passportNumber;
}

const Border *Tourist::getBorder() const {
    return border;
}

void Tourist::setBorder(Border *border) {
    Tourist::border = border;
}

template <class T>
std::istream &operator>>(std::istream &is, Tourist &tourist) {
    is >> dynamic_cast<Person&>(tourist);
    rewind(stdin);
    tourist.passportNumber = InputError::input(100000, 999999);
    std::cout << "Write the size of borders: ";
    tourist.borderSize = InputError::input(0, 1000);
    tourist.border = MemoryError<T>::getMemory(tourist.border, tourist.borderSize);
    is.get();
    char *buffer = nullptr;
    for (int i = 0; i < tourist.borderSize; ++i) {
        buffer = InputError::inputString();
        strcpy(tourist.border[i].date, buffer);
        buffer = InputError::inputString();
        strcpy(tourist.border[i].country, buffer);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Tourist &tourist) {
    os << static_cast<const Person &>(tourist) << tourist.passportNumber << std::setw(10) << "|" << std::endl;
    os << std::setw(10) << "Date" << " | " << std::setw(10) << "Country" << std::endl;
    for (int i = 0; i < tourist.borderSize; ++i) {
        os << tourist.border[i].date << " - " << tourist.border[i].country << std::endl;
    }
    return os;
}

void Tourist::table() {
    std::cout << std::setw(10) << "Surname" << "|"
              << std::setw(10) << "Name" << "|B. Year|" << std::setw(10) << "Passport" << "|" << std::endl;
}

char *Tourist::getDate(int index) const {
    if (index >= 0 || index < borderSize) {
        return this->border[index].date;
    } else {
        return nullptr;
    }
}

void Tourist::setDate(char *date, int index) {
    if (index >= 0 || index < borderSize) {
        strcpy(this->border[index].date, date);
    }
}

char *Tourist::getCountry(int index) const {
    if (index >= 0 || index < borderSize) {
        return this->border[index].country;
    } else {
        return nullptr;
    }
}

void Tourist::setCountry(char *country, int index) {
    if (index >= 0 || index < borderSize) {
        strcpy(this->border[index].country, country);
    }
}

int Tourist::getBorderSize() const {
    return borderSize;
}

void Tourist::setBorderSize(int borderSize) {
    Tourist::borderSize = borderSize;
}