#include <iostream>
#include "Subject.h"

#ifndef SCHOLARSHIP_SESSION_H
#define SCHOLARSHIP_SESSION_H

class Session : public Subject {
protected:
    bool debt;
    int number;
public:
    explicit Session(const bool &debt = false, const int number = 1, std::string name = "0", int subMark = 0) : debt(debt),
                                                        number(number), Subject(name, subMark){};
    Session(const Session &obj);
    ~Session() = default;

    const bool &getDebt() const;
    void setDebt(const bool &debt);
    const int &getNumber() const;
    void setNumber(int number);

    friend std::istream &operator>>(std::istream &is, Session &session);
    friend std::ostream &operator<<(std::ostream &os, Session &session);
};

#endif