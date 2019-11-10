//
// Created by danpe on 08.11.2019.
//

#ifndef EXCEPTIONS_TOURIST_H
#define EXCEPTIONS_TOURIST_H

#include <ostream>
#include "Person.h"

struct Border {
    char *date = "";
    char *country = "";
};

class Tourist : public virtual Person {
protected:
    int passportNumber = 0;
    int borderSize;
    Border *border;
public:
    explicit Tourist(char *surname = "", char *name = "",
                     int birthdayYear = 0, int passportNumber = 0);

    int getBorderSize() const;
    void setBorderSize(int borderSize);
    int getPassportNumber() const;
    void setPassportNumber(int passportNumber);
    const Border *getBorder() const;
    void setBorder(Border *border);
    char *getDate(int index) const;
    void setDate(char *date, int index);
    char *getCountry(int index) const;
    void setCountry(char *country, int index);

    friend std::ostream &operator<<(std::ostream &os, const Tourist &tourist);
    template <class T>
    friend std::istream &operator>>(std::istream &is, Tourist &tourist);

    void table() override;
};


#endif //EXCEPTIONS_TOURIST_H
