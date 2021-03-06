#include <iostream>
#include "../Headers/Salary.h"
#include "../Headers/InputError.h"

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
    os << "Зарплата: " << salary.salary << std::endl << "Номер счёта: " << salary.bankBook << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Salary &salary) {
    std::cout << "Введите номер лицевого счёта сотрудника: ";
    salary.bankBook = InputError::Input(100000, 999999);
    std::cout << "Введите зарплату сотрудника: ";
    salary.salary = InputError::Input(0, 1000000);
    return is;
}
