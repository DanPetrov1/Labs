//
// Created by danpe on 08.11.2019.
//

#include "../Headers/Businessman.h"
#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/InputError.h"
#include "../Headers/MemoryError.h"
#include <string>
#include <iomanip>

Businessman::Businessman(char *surname, char *name, int birthdayYear,
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

char *Businessman::getDate(int index) const {
    return this->payment[index].date;
}

void Businessman::setDate(char *date, int index) {
    strcpy(this->payment[index].date, date);
}

char *Businessman::getCountry(int index) const {
    return this->payment[index].country;
}

void Businessman::setCountry(char *country, int index) {
    strcpy(this->payment[index].country, country);
}

template <class T>
std::istream &operator>>(std::istream &is, Businessman &businessman) {
    is >> dynamic_cast<Person&>(businessman);
    rewind(stdin);
    businessman.licenceNumber = InputError::input(100000, 999999);
    std::cout << "Write the number of payments: ";
    businessman.paymentSize = InputError::input(0, 1000);
    businessman.payment = MemoryError<T>::getMemory(businessman.payment, businessman.paymentSize);
    is.get();
    char*buffer = nullptr;
    for (int i = 0; i < businessman.paymentSize; ++i) {
        buffer = InputError::inputString();
        strcpy(businessman.payment[i].date, buffer);
        buffer = InputError::inputString();
        strcpy(businessman.payment[i].country, buffer);
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