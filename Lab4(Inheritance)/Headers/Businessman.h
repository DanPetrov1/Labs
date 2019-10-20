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
};

class Businessman : Person {
protected:
    int licenceNumber;
    int paymentSize = 0;
    Payment* payment;
public:
    explicit Businessman(std::string surname = "", std::string name = "", int birthdayYear = 0,
            int licenceNumber = 0);

    int getPaymentSize() const;
    void setPaymentSize(int paymentSize);
    int getLicenceNumber() const;
    void setLicenceNumber(int licenceNumber);
    const Payment *getPayment() const;
    void setPayment(Payment *payment);
    const std::string& getDate(int index) const;
    void setDate(const std::string& date, int index);
    const std::string& getCountry(int index) const;
    void setCountry(const std::string& country, int index);

    friend std::istream &operator>>(std::istream &is, Businessman &businessman);
    friend std::ostream &operator<<(std::ostream &os, const Businessman &businessman);
};


#endif //LAB4_INHERITANCE__BUSINESSMAN_H
