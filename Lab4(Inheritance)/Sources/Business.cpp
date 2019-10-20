//
// Created by dan on 19.10.19.
//

#include "../Headers/Business.h"
#include "stdio_ext.h"

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
    std::cout << "Write the number of addresses: ";
    is >> business.addressSize;
    __fpurge(stdin);
    is.get();
    business.address = new std::string[business.addressSize];
    for (int i = 0; i < business.addressSize; ++i) {
        getline(is, business.address[i]);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Business &business) {
    for (int i = 0; i < business.addressSize; ++i) {
        std::cout << business.address[i] << std::endl;
    }
    return os;
}
