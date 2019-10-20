//
// Created by dan on 19.10.19.
//

#include "../Headers/Business.h"
#include "stdio_ext.h"

Business::Business(std::string surname, std::string name, int birthdayYear, int licenceNumber, std::string date,
                   std::string country, int passportNumber, std::string date2, std::string country2,
                   std::string address[10]) : Businessman(surname, name, birthdayYear, licenceNumber, date, country),
                   Tourist(surname, name, birthdayYear, passportNumber, date2, country2) {
}

const std::string *Business::getAddress() const {
    return address;
}

void Business::setAddress(const std::string address[10]) {
    for (int i = 0; i < 10; ++i) {
        this->address[i] = address[i];
    }
}

std::istream &operator>>(std::istream &is, Business &business) {
    is >> dynamic_cast<Businessman&>(business);
    std::cout << "Write the number of addresses: ";
    int number;
    is >> number;
    __fpurge(stdin);
    for (int i = 0; i < number; ++i) {
        is >> business.address[i];
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Business &business) {
    os << static_cast<const Businessman &>(business) << ' ' << static_cast<const Tourist &>(business) << "address: "
       << business.address;
    return os;
}
