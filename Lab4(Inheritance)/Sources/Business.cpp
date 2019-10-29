//
// Created by dan on 19.10.19.
//

#include <iomanip>
#include "../Headers/Business.h"
#include "stdio_ext.h"
#include "../Headers/InputError.h"

Business::Business(std::string surname, std::string name, int birthdayYear, int licenceNumber,
        int passportNumber, std::string address[10]) : Businessman(surname, name, birthdayYear,
                licenceNumber), Tourist(surname, name, birthdayYear, passportNumber) {
}

const std::string *Business::getAddress() const {
    return address;
}

void Business::setAddress(std::string *address) {
    this->address = address;
}

std::istream &operator>>(std::istream &is, Business &business) {
    is >> dynamic_cast<Person&>(business);
    business.licenceNumber = InputError::input(100000, 999999);
    business.passportNumber = InputError::input(100000, 999999);
    std::cout << "Write the number of addresses: ";
    business.addressSize = InputError::input(0, 100);
    __fpurge(stdin);
    business.address = new std::string[business.addressSize];
    for (int i = 0; i < business.addressSize; ++i) {
        getline(is, business.address[i]);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, Business &business) {
    for (int i = 0; i < business.addressSize; ++i) {
        os << std::setw(10) << business.address[i] << "|";
        if (i == 0) {
            os << std::setw(10) << business.surname << "|" << std::setw(10) << business.name << "|"
                    << std::setw(7) << business.birthdayYear << "|" << std::setw(10) << business.passportNumber <<
            "|" << std::setw(10) << business.licenceNumber << "|";
        }
        os << std::endl;
    }
    return os;
}

void Business::table() {
    std::cout << std::setw(10) << "Address" << "|" << std::setw(10) << "Surname" << "|"
    << std::setw(10) << "Name"<< "|B. Year|" << std::setw(10) << "License" << "|" << std::setw(10) << "Passport"
    << "|" << std::endl;
}
