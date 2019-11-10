//
// Created by danpe on 08.11.2019.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "../Headers/Business.h"
#include "../Headers/InputError.h"

Business::Business(char *surname, char *name, int birthdayYear, int licenceNumber,
                   int passportNumber, char **address) : Businessman(surname, name, birthdayYear,
                           licenceNumber), Tourist(surname, name, birthdayYear, passportNumber) {
    this->addressSize = 0;
    this->address = new char*[1];
    this->address[0] = new char[1];
}

char **Business::getAddress() const {
    return address;
}

void Business::setAddress(char **address) {
    for (int i = 0; i < _msize(address)/_msize(address[0]) && address[i]; ++i) {
        strcpy(this->address[i], address[i]);
    }
}

std::istream &operator>>(std::istream &is, Business &business) {
    is >> dynamic_cast<Person&>(business);
    business.licenceNumber = InputError::input(100000, 999999);
    business.passportNumber = InputError::input(100000, 999999);
    std::cout << "Write the number of addresses: ";
    business.addressSize = InputError::input(0, 100);
    rewind(stdin);
    char* buffer = nullptr;
    business.address = new char*[business.addressSize];
    for (int i = 0; i < business.addressSize; ++i) {
        business.address[i] = new char[1];
        buffer = InputError::inputString();
        strcpy(business.address[i], buffer);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, Business &business) {
    for (int i = 0; i < business.addressSize; ++i) {
        os << std::setw(10) << business.address[i] << "|";
        if (i == 0) {
            os << std::setw(10) << business.surname << "|" << std::setw(10) << business.name << "|"
               << std::setw(7) << business.birthdayYear << "|" << std::setw(7) << business.licenceNumber <<
               "|" << std::setw(8) << business.passportNumber << "|";
        }
        os << std::endl;
    }
    return os;
}

void Business::table() {
    std::cout << std::left << std::setw(10) << "Address" << "|" << std::setw(10) << "Surname" << "|"
              << std::setw(10) << "Name"<< "|B. Year|" << std::setw(7) << "License" << "|" << std::setw(7) << "Passport"
              << "|" << std::endl;
}