#include <iostream>
#include "../Headers/Trainee.h"
#include "../Headers/InputError.h"

Trainee::Trainee(int salary, int bankBook, int group, int numberOfCompletedTasks) : Salary(salary,bankBook), group(group),
    numberOfCompletedTasks(numberOfCompletedTasks) {
}

int Trainee::getGroup() const {
    return group;
}

void Trainee::setGroup(int group) {
    Trainee::group = group;
}

int Trainee::getNumberOfCompletedTasks() const {
    return numberOfCompletedTasks;
}

void Trainee::setNumberOfCompletedTasks(int numberOfCompletedTasks) {
    Trainee::numberOfCompletedTasks = numberOfCompletedTasks;
}

std::ostream &operator<<(std::ostream &os, const Trainee &trainee) {
    os << "№ группы: " << trainee.group << std::endl << "Количество выполненных задач: "
       << trainee.numberOfCompletedTasks << std::endl;
    os << static_cast<const Salary &>(trainee);
    return os;
}

std::istream &operator>>(std::istream &is, Trainee &trainee) {
    std::cout << "Введите номер группы стажёра: ";
    trainee.group = InputError::Input(100000, 999999);
    std::cout << "Введите количество заданий, выполненных стажёром: ";
    trainee.numberOfCompletedTasks = InputError::Input(0, 1000);
    is >> dynamic_cast<Salary&>(trainee);
    return is;
}
