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
};

class Tourist : public virtual Person {
protected:
    int passportNumber = 0;
    int borderSize;
    Border *border;
public:
    explicit Tourist(std::string surname = "", std::string name = "",
            int birthdayYear = 0, int passportNumber = 0);

    int getBorderSize() const;
    void setBorderSize(int borderSize);
    int getPassportNumber() const;
    void setPassportNumber(int passportNumber);
    const Border *getBorder() const;
    void setBorder(Border *border);
    const std::string& getDate(int index) const;
    void setDate(const std::string& date, int index);
    const std::string& getCountry(int index) const;
    void setCountry(const std::string& country, int index);

    friend std::ostream &operator<<(std::ostream &os, const Tourist &tourist);
    template <class T>
    friend std::istream &operator>>(std::istream &is, Tourist &tourist);

    void table() override;
};


#endif //LAB4_INHERITANCE__TOURIST_H
