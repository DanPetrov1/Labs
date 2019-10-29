//
// Created by dan on 19.10.19.
//

#include "../Headers/Businessman.h"
#include "stdio_ext.h"
#include "../Headers/InputError.h"
#include "../Headers/MemoryError.h"
#include <string>
#include <iomanip>

Businessman::Businessman(std::string surname, std::string name, int birthdayYear,
        int licenceNumber) : Person(surname, name, birthdayYear), licenceNumber(licenceNumber) {
    this->payment = nullptr;
    this->paymentSize = 0;
}

int Businessman::getLicenceNumber() const {
    return licenceNumber;
}

void Businessman::setLicenceNumber(int licenceNumber) {
    Businessman::licenceNumber = licenceNumber;
}

const Payment *Businessman::getPayment() const {
    return payment;
}

void Businessman::setPayment(Payment *payment) {
    this->payment = payment;
}

const std::string &Businessman::getDate(int index) const {
    return this->payment[index].date;
}

void Businessman::setDate(const std::string &date, int index) {
    this->payment[index].date = date;
}

const std::string &Businessman::getCountry(int index) const {
    return this->payment[index].country;
}

void Businessman::setCountry(const std::string &country, int index) {
    this->payment[index].country = country;
}

template <class T>
std::istream &operator>>(std::istream &is, Businessman &businessman) {
    is >> dynamic_cast<Person&>(businessman);
    __fpurge(stdin);
    businessman.licenceNumber = InputError::input(100000, 999999);
    std::cout << "Write the number of payments: ";
    businessman.paymentSize = InputError::input(0, 1000);
    businessman.payment = MemoryError<T>::getMemory(businessman.payment, businessman.paymentSize);
    is.get();
    for (int i = 0; i < businessman.paymentSize; ++i) {
        is >> businessman.payment[i].date;
        is >> businessman.payment[i].country;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Businessman &businessman) {
    os << static_cast<const Person &>(businessman)
    << businessman.licenceNumber << std::setw(10) << "|";
    os << std::setw(10) << "Date" << " | " << std::setw(10) << "Country" << std::endl;
    for (int i = 0; i < businessman.paymentSize; ++i) {
        os << businessman.payment[i].date << " - " << businessman.payment[i].country << std::endl;
    }
    return os;
}

int Businessman::getPaymentSize() const {
    return paymentSize;
}

void Businessman::setPaymentSize(int paymentSize) {
    Businessman::paymentSize = paymentSize;
}

void Businessman::table() {
    std::cout << std::setw(10) << "Surname" << "|"
            << std::setw(10) << "Name" << "|B. Year|" << std::setw(10) << "License" << "|" << std::endl;
}
