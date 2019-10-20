//
// Created by dan on 19.10.19.
//

#include "../Headers/Businessman.h"
#include "stdio_ext.h"
#include <string>

Businessman::Businessman(std::string surname, std::string name, int birthdayYear, int licenceNumber, std::string date,
        std::string country) : Person(surname, name, birthdayYear), licenceNumber(licenceNumber), payment(date, country) {
}

int Businessman::getLicenceNumber() const {
    return licenceNumber;
}

void Businessman::setLicenceNumber(int licenceNumber) {
    Businessman::licenceNumber = licenceNumber;
}

const Payment &Businessman::getPayment() const {
    return payment;
}

void Businessman::setPayment(const Payment &payment) {
    Businessman::payment = payment;
}

const std::string &Businessman::getDate() const {
    return this->payment.date;
}

void Businessman::setDate(const std::string &date) {
    this->payment.date = date;
}

const std::string &Businessman::getCountry() const {
    return this->payment.country;
}

void Businessman::setCountry(const std::string &country) {
    this->payment.country = country;
}

std::istream &operator>>(std::istream &is, Businessman &businessman) {
    is >> dynamic_cast<Person&>(businessman);
    __fpurge(stdin);
    is >> businessman.payment.date;
    is >> businessman.payment.country;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Businessman &businessman) {
    os << static_cast<const Person &>(businessman)
    << "licenceNumber: " << businessman.licenceNumber << std::endl << "payment: "
       << businessman.payment.date << " " << businessman.payment.country << std::endl;
    return os;
}
