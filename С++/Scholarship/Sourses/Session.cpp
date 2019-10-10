#include <iostream>
#include <iomanip>
#include "../Headers/Session.h"
#include "../Headers/InputError.h"

Session::Session(const Session &obj) : Subject(obj.subjectName, obj.mark) {
    this->number = obj.number;
    this->debt = obj.debt;
}

const bool &Session::getDebt() const {
    return this->debt;
}

void Session::setDebt(const bool &debt) {
    this->debt = debt;
}

void Session::setNumber(const int number) {
    this->number = number;
}

std::ostream &operator<<(std::ostream &os, Session &session) {
    os << "|" << std::setw(5) << session.debt;
    os << "|" << std::setw(8) << session.number;
    os << dynamic_cast<Subject&>(session);
    return os;
}

std::istream &operator>>(std::istream &is, Session &session) {
    std::cout << "Есть ли задолженности у студента? (1. Да. 2. Нет.) ";
    session.debt = static_cast<bool>(InputError::input(1, 2) % 2);
    std::cout << "Введите номер сессии: ";
    session.number = InputError::input(1, 10);
    is >> dynamic_cast<Subject&>(session);
    return is;
}

const int &Session::getNumber() const {
    return this->number;
}
