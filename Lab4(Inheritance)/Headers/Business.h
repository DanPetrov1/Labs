//
// Created by dan on 19.10.19.
//

#ifndef LAB4_INHERITANCE__BUSINESS_H
#define LAB4_INHERITANCE__BUSINESS_H


#include <ostream>
#include "Businessman.h"
#include "Tourist.h"

class Business : public Businessman, public Tourist {
private:
    int addressSize;
    std::string *address;
public:
    explicit Business(std::string surname = "", std::string name = "", int birthdayYear = 0,
             int licenceNumber = 0, int passportNumber = 0, std::string address[10] = {});

    const std::string *getAddress() const;
    void setAddress(std::string *address);

    friend std::istream &operator>>(std::istream &is, Business &business);
    friend std::ostream &operator<<(std::ostream &os, Business &business);

    void table() final;
};


#endif //LAB4_INHERITANCE__BUSINESS_H
