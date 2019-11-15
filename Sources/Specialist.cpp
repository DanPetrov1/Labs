#include "../Headers/Specialist.h"
#include "../Headers/InputError.h"
#include <string>
#include <iostream>

Specialist::Specialist(int salary, int bankBook, int numberOfProjects, int workExperience, char *specialSkills) :
    Salary(salary, bankBook), numberOfProjects(numberOfProjects), workExperience(workExperience) {
    strcpy_s(this->specialSkills, specialSkills);
}

int Specialist::getNumberOfProjects() const {
    return numberOfProjects;
}

void Specialist::setNumberOfProjects(int numberOfProjects) {
    Specialist::numberOfProjects = numberOfProjects;
}

int Specialist::getWorkExperience() const {
    return workExperience;
}

void Specialist::setWorkExperience(int workExperience) {
    Specialist::workExperience = workExperience;
}

const char *Specialist::getSpecialSkills() const {
    return specialSkills;
}

void Specialist::setSpecialSkills(const char *specialSkills) {
    strcpy_s(Specialist::specialSkills, specialSkills);
}

std::ostream &operator<<(std::ostream &os, const Specialist &specialist) {
    os << "Количество выполненных проектов: " << specialist.numberOfProjects << std::endl
       << "Опыт работы: " << specialist.workExperience << std::endl << "Особые навыки: " << specialist.specialSkills << std::endl;
    os << static_cast<const Salary &>(specialist);
    return os;
}

std::istream &operator>>(std::istream &is, Specialist &specialist) {
    std::cout << "Введите количество проектов, которые выполнил специалист: ";
    specialist.numberOfProjects = InputError::Input(0, 1000);
    std::cout << "Введите стаж работы специалиста: ";
    specialist.workExperience = InputError::Input(0, 100);
    rewind(stdin);
    std::cout << "Введите особые умения специалиста: ";
    is >> specialist.specialSkills;
    is >> static_cast<Salary&>(specialist);
    return is;
}
