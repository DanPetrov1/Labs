//
// Created by danpe on 08.11.2019.
//

#ifndef EXCEPTIONS_BUSINESS_H
#define EXCEPTIONS_BUSINESS_H

#include <ostream>
#include "Businessman.h"
#include "Tourist.h"

class Business : public Businessman, public Tourist {
private:
    int addressSize;
    char **address;
public:
    explicit Business(char *surname = "", char *name = "", int birthdayYear = 0,
                      int licenceNumber = 0, int passportNumber = 0, char** address = nullptr);

    char **getAddress() const;
    void setAddress(char **address);

    friend std::istream &operator>>(std::istream &is, Business &business);
    friend std::ostream &operator<<(std::ostream &os, Business &business);

    void table() final;
};

#endif //EXCEPTIONS_BUSINESS_H
