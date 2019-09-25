#include <iostream>

class Session {
protected:
    bool debt;
    int mark;
public:
    Session(const bool &debt = false, int mark = 0) : debt(debt), mark(mark){};
    Session(const Session&);
    ~Session(){};

    const bool &getDebt() const;
    void setDebt(const bool &debt);
    int getMark() const;
    void setMark(int mark);

    friend std::istream &operator>>(std::istream &is, Session &session);
    friend std::ostream &operator<<(std::ostream &os, const Session &session);
};
