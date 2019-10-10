#include <iomanip>
#include <string>
#include <stdlib.h>
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

std::istream &operator>>(std::istream &is, Student &obj) {
    is.get();
    std::cout << "Введите специальность: ";
    getline(is, obj.specialty);
    std::cout << "Введите № группы: ";
    obj.group = InputError::input(100000, 999999);
    is.get();
    std::cout << "Введите ФИО студента: ";
    getline(is, obj.name);
    std::cout << "Есть ли льготы у студента? (1. Да. 2. Нет.) ";
    obj.privilege = static_cast<bool>(InputError::input(1, 2) % 2);
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
    os << "|" << std::setw(15) << obj.specialty;
    os << "|" << std::setw(6) << obj.group;
    os << "|" << std::setw(25) << obj.name;
    os << dynamic_cast<Session&>(obj);
    os << "|" << std::setw(2) << obj.privilege;
    os << "|" << std::setw(8) << obj.scholarship << "$|";
    return os;
}

const std::string &Student::getSpecialty() const {
    return specialty;
}

void Student::setSpecialty(const std::string &specialty) {
    Student::specialty = specialty;
}

void Student::table() {
    std::cout << "|" << std::setw(3) << "№  ";
    std::cout << "|" << std::setw(15) << "Факультет";
    std::cout << "|" << std::setw(6) << "Группа";
    std::cout << "|" << std::setw(25) << "Фамилия и имя  ";
    std::cout << "|" << std::setw(5) << "Долги";
    std::cout << "|" << std::setw(10) << "№ сессии";
    std::cout << "|" << std::setw(10) << "Предмет";
    std::cout << "|" << std::setw(4) << "Балл";
    std::cout << "|" << std::setw(2) << "Пр";
    std::cout << "|" << std::setw(9) << "Стипендия";
    std::cout << "|" << std::endl;
}

