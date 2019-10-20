//
// Created by dan on 18.10.19.
//

#ifndef LAB4_INHERITANCE__TOURIST_H
#define LAB4_INHERITANCE__TOURIST_H

#include <ostream>
#include "Person.h"

struct Border {
    std::string date = "";
    std::string country = "";
    Border(std::string date, std::string country);
};

class Tourist : public Person {
protected:
    int passportNumber = 0;
    Border border;
public:
    Tourist(std::string surname = "", std::string name = "", int birthdayYear = 0, int passportNumber = 0, std::string date = "", std::string country = "");

    int getPassportNumber() const;
    void setPassportNumber(int passportNumber);
    const Border &getBorder() const;
    void setBorder(const Border &border);
    const std::string& getDate() const;
    void setDate(const std::string& date);
    const std::string& getCountry() const;
    void setCountry(const std::string& country);

    friend std::ostream &operator<<(std::ostream &os, const Tourist &tourist);
    friend std::istream &operator>>(std::istream &is, Tourist &tourist);
    };


#endif //LAB4_INHERITANCE__TOURIST_H
