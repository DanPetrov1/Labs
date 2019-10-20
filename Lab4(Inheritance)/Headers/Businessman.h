//
// Created by dan on 19.10.19.
//

#ifndef LAB4_INHERITANCE__BUSINESSMAN_H
#define LAB4_INHERITANCE__BUSINESSMAN_H


#include <ostream>
#include "Person.h"

struct Payment {
    std::string date;
    std::string country;
    explicit Payment(std::string date = "", std::string country = "") : date(date), country(country){}
};

class Businessman : Person {
protected:
    int licenceNumber;
    Payment payment;
public:
    explicit Businessman(std::string surname = "", std::string name = "", int birthdayYear = 0, int licenceNumber = 0,
            std::string date = "", std::string country = "");

    int getLicenceNumber() const;
    void setLicenceNumber(int licenceNumber);
    const Payment &getPayment() const;
    void setPayment(const Payment &payment);
    const std::string& getDate() const;
    void setDate(const std::string& date);
    const std::string& getCountry() const;
    void setCountry(const std::string& country);

    friend std::istream &operator>>(std::istream &is, Businessman &businessman);

    friend std::ostream &operator<<(std::ostream &os, const Businessman &businessman);
};


#endif //LAB4_INHERITANCE__BUSINESSMAN_H
