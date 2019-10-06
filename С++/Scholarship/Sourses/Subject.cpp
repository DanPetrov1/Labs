#include <iostream>
#include <iomanip>
#include "../Headers/Subject.h"
#include "../Headers/InputError.h"

std::istream &operator>>(std::istream &is, Subject& sub) {
    std::cout << "Введите название предмета: ";
    is.get();
    getline(is, sub.subjectName);
    std::cout << "Введите оценку по предмету: ";
    sub.mark = InputError::Input(0, 10);
    return is;
}

std::ostream &operator<<(std::ostream &os, Subject &sub) {
    os << "|" << std::setw(11) << sub.subjectName;
    os << "|" << std::setw(4) << sub.mark;
    return os;
}

const std::string &Subject::getSubjectName() const { return this->subjectName; }

void Subject::setSubjectName(const std::string &subjectName) { this->subjectName = subjectName; }

int Subject::getMark() const { return this->mark; }

void Subject::setMark(int mark) { this->mark = mark; }
