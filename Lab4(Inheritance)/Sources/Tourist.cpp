//
// Created by dan on 18.10.19.
//

#include "../Headers/Tourist.h"
#include "stdio_ext.h"
#include "../Headers/InputError.h"
#include "../Headers/MemoryError.h"
#include <string>
#include <iomanip>

Tourist::Tourist(std::string surname, std::string name, int birthdayYear,
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
    __fpurge(stdin);
    tourist.passportNumber = InputError::input(100000, 999999);
    std::cout << "Write the size of borders: ";
    tourist.borderSize = InputError::input(0, 1000);
    tourist.border = MemoryError<T>::getMemory(tourist.border, tourist.borderSize);
    is.get();
    for (int i = 0; i < tourist.borderSize; ++i) {
        is >> tourist.border[i].date;
        is >> tourist.border[i].country;
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

const std::string &Tourist::getDate(int index) const {
    if (index >= 0 || index < borderSize) {
        return this->border[index].date;
    } else {
        return nullptr;
    }
}

void Tourist::setDate(const std::string &date, int index) {
    if (index >= 0 || index < borderSize) {
        this->border[index].date = date;
    }
}

const std::string &Tourist::getCountry(int index) const {
    if (index >= 0 || index < borderSize) {
        return this->border[index].country;
    } else {
        return nullptr;
    }
}

void Tourist::setCountry(const std::string &country, int index) {
    if (index >= 0 || index < borderSize) {
        this->border[index].country = country;
    }
}

int Tourist::getBorderSize() const {
    return borderSize;
}

void Tourist::setBorderSize(int borderSize) {
    Tourist::borderSize = borderSize;
}
