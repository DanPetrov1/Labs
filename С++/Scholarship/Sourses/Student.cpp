#include <iomanip>
#include <string>
#include "../Headers/InputError.h"
#include "../Headers/Student.h"

int Student::getGroup() const {
    return group;
}

void Student::setGroup(int group) {
    Student::group = group;
}

const std::string &Student::getName() const {
    return name;
}

void Student::setName(const std::string &name) {
    Student::name = name;
}

bool Student::isPrivilege() const {
    return privilege;
}

void Student::setPrivilege(bool privilege) {
    Student::privilege = privilege;
}

int Student::getScholarship() const {
    return scholarship;
}

void Student::setScholarship(int scholarship) {
    Student::scholarship = scholarship;
}

Student::Student(const Student& obj) {
    this->name = obj.name;
    this->group = obj.group;
    this->privilege = obj.privilege;
    this->scholarship = obj.scholarship;
    this->debt = obj.debt;
    this->mark = obj.mark;
}

std::istream &operator>>(std::istream &is, Student &obj) {
    std::cout << "Введите специальность: ";
    getline(is, obj.specialty);
    std::cout << "Введите № группы: ";
    obj.group = InputError::Input(100000, 999999);
    is.get();
    std::cout << "Введите ФИО студента: ";
    getline(is, obj.name);
    std::cout << "Есть ли льготы у студента? (1. Да. 2. Нет.) ";
    obj.privilege = static_cast<bool>(InputError::Input(1, 2) % 2);
    if (obj.privilege) {
        obj.scholarship += 100;
    }
    is.get();
    is >> dynamic_cast<Session&>(obj);
    if (!obj.getDebt()) {
        switch (obj.getMark()) {
            case 4: case 5: case 6: {
                obj.scholarship += 100;
                break;
            }
            case 7: {
                obj.scholarship += 120;
                break;
            }
            case 8: {
                obj.scholarship += 140;
                break;
            }
            case 9: case 10: {
                obj.scholarship += 160;
                break;
            }
            default: {
                std::cout << "Ошибка! Студент без задолжностей не может иметь такой балл!" << std::endl;
                break;
            }
        }
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, Student &obj) {
    os << "|" << std::setw(11) << obj.specialty;
    os << "|" << std::setw(11) << obj.group;
    os << "|" << std::setw(11) << obj.name;
    os << dynamic_cast<Session&>(obj);
    os << "|" << std::setw(11) << obj.privilege;
    os << "|" << std::setw(11) << obj.scholarship << "$|";
    return os;
}

const std::string &Student::getSpecialty() const {
    return specialty;
}

void Student::setSpecialty(const std::string &specialty) {
    Student::specialty = specialty;
}

