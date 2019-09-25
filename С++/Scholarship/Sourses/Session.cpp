#include <iostream>
#include <iomanip>
#include "../Headers/Session.h"
#include "../Headers/InputError.h"

Session::Session(const Session &obj) {
    this->mark = obj.mark;
    this->debt = obj.debt;
}

const bool &Session::getDebt() const {
    return debt;
}

void Session::setDebt(const bool &debt) {
    this->debt = debt;
}

int Session::getMark() const {
    return mark;
}

void Session::setMark(int mark) {
    this->mark = mark;
}

std::ostream &operator<<(std::ostream &os, const Session &session) {
    os << "|" << std::setw(11) << session.debt << "|" << std::setw(11) << session.mark;
    return os;
}

std::istream &operator>>(std::istream &is, Session &session) {
    std::cout << "Есть ли задолженности у студента? (1. Да. 2. Нет.) ";
    session.debt = static_cast<bool>(InputError::Input(1, 2) % 2);
    std::cout << "Введите средний балл студента (округлённый по всем правилам математики): ";
    session.mark = InputError::Input(0, 10);
    return is;
}
