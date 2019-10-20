//
// Created by dan on 18.10.19.
//

#include "../Headers/Tourist.h"
#include "stdio_ext.h"
#include <string>

Tourist::Tourist(std::string surname, std::string name, int birthdayYear, int passportNumber, std::string date,
        std::string country) : Person(surname, name, birthdayYear), border(date, country) {
}

int Tourist::getPassportNumber() const {
    return passportNumber;
}

void Tourist::setPassportNumber(int passportNumber) {
    Tourist::passportNumber = passportNumber;
}

const Border &Tourist::getBorder() const {
    return border;
}

void Tourist::setBorder(const Border &border) {
    Tourist::border = border;
}

std::istream &operator>>(std::istream &is, Tourist &tourist) {
    is >> dynamic_cast<Person&>(tourist);
    is >> tourist.passportNumber;
    __fpurge(stdin);
    is >> tourist.border.date;
    is >> tourist.border.country;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Tourist &tourist) {
    os << static_cast<const Person &>(tourist) << "passportNumber: " << tourist.passportNumber << std::endl
        << "border: " << tourist.border.date << " " << tourist.border.country << std::endl;
    return os;
}

const std::string &Tourist::getDate() const {
    return this->border.date;
}

void Tourist::setDate(const std::string &date) {
    this->border.date = date;
}

const std::string &Tourist::getCountry() const {
    return this->border.country;
}

void Tourist::setCountry(const std::string &country) {
    this->border.country = country;
}

Border::Border(std::string date, std::string country) : date(date), country(country) {
}
