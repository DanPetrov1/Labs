#include <iostream>
#include "../Headers/Supervisor.h"
#include "../Headers/InputError.h"

Supervisor::Supervisor(int salary, int bankBook, int numberOfProjects, int workExperience, char *specialSkills,
                       int departmentNumber, bool retraining) : Specialist(salary, bankBook, numberOfProjects,
                               workExperience, specialSkills), departmentNumber(departmentNumber), retraining(retraining) {
}

int Supervisor::getDepartmentNumber() const {
    return departmentNumber;
}

void Supervisor::setDepartmentNumber(int departmentNumber) {
    Supervisor::departmentNumber = departmentNumber;
}

bool Supervisor::isRetraining() const {
    return retraining;
}

void Supervisor::setRetraining(bool retraining) {
    Supervisor::retraining = retraining;
}

std::ostream &operator<<(std::ostream &os, const Supervisor &supervisor) {
    os << "Номер отдела: " << supervisor.departmentNumber << std::endl
       << "Пройденная переподготовка: " << supervisor.retraining << std::endl
       << static_cast<const Specialist &>(supervisor);
    return os;
}

std::istream &operator>>(std::istream &is, Supervisor &supervisor) {
    std::cout << "Введите номер отдела данного руководителя: ";
    supervisor.departmentNumber = InputError::InputNumber();
    is >> static_cast<Specialist&>(supervisor);
    return is;
}
