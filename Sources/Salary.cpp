#include "../Headers/Salary.h"

Salary::Salary(int salary, int bankBook) : salary(salary), bankBook(bankBook) {
}

int Salary::getSalary() const {
    return salary;
}

void Salary::setSalary(int salary) {
    Salary::salary = salary;
}

int Salary::getBankBook() const {
    return bankBook;
}

void Salary::setBankBook(int bankBook) {
    Salary::bankBook = bankBook;
}

std::ostream &operator<<(std::ostream &os, const Salary &salary) {
    os << "salary: " << salary.salary << std::endl << "bankBook: " << salary.bankBook << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Salary &salary) {
    return is;
}
