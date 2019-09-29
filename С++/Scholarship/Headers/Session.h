#include <iostream>

#ifndef SCHOLARSHIP_SESSION_H
#define SCHOLARSHIP_SESSION_H

class Session {
protected:
    bool debt;
    int mark;
public:
    Session(const bool &debt = false, int mark = 0) : debt(debt), mark(mark){};
    Session(const Session&);
    ~Session() = default;;

    const bool &getDebt() const;
    void setDebt(const bool &debt);
    int getMark() const;
    void setMark(int mark);

    friend std::istream &operator>>(std::istream &is, Session &session);
    friend std::ostream &operator<<(std::ostream &os, const Session &session);
};

#endif