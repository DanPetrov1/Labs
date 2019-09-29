#include <iomanip>
#include "../Headers/GraduateStudent.h"
#include "../Headers/InputError.h"

GraduateStudent::GraduateStudent(int group, const std::string &specialty, const std::string &name, bool privilege,
                                    int scholarship, int numberOfPublications, const std::string &specialSkills,
                                 const bool &debt, int mark) : Session(debt, mark), group(group),
                                                                     specialty(specialty), name(name),
                                                                     privilege(privilege), scholarship(scholarship),
                                                                     numberOfPublications(numberOfPublications),
                                                                     specialSkills(specialSkills) {}

int GraduateStudent::getGroup() const { return this->group; }

void GraduateStudent::setGroup(int group) { this->group = group; }

const std::string &GraduateStudent::getSpecialty() const { return this->specialty; }

void GraduateStudent::setSpecialty(const std::string &specialty) { this->specialty = specialty; }

const std::string &GraduateStudent::getName() const { return this->name; }

void GraduateStudent::setName(const std::string &name) { this->name = name; }

bool GraduateStudent::isPrivilege() const { return this->privilege; }

void GraduateStudent::setPrivilege(bool privilege) { this->privilege = privilege; }

int GraduateStudent::getScholarship() const { return this->scholarship; }

void GraduateStudent::setScholarship(int scholarship) { this->scholarship = scholarship; }

int GraduateStudent::getNumberOfPublications() const { return this->numberOfPublications; }

void GraduateStudent::setNumberOfPublications(int numberOfPublications) { this->numberOfPublications = numberOfPublications; }

const std::string &GraduateStudent::getSpecialSkills() const { return this->specialSkills; }

void GraduateStudent::setSpecialSkills(const std::string &specialSkills) { this->specialSkills = specialSkills; }

std::ostream &operator<<(std::ostream &os, GraduateStudent &student) {
    os << "|" << std::setw(11) << student.specialty;
    os << "|" << std::setw(11) << student.group;
    os << "|" << std::setw(11) << student.name;
    os << "|" << std::setw(11) << student.specialSkills;
    os << "|" << std::setw(11) << student.numberOfPublications;
    os << dynamic_cast<Session&>(student);
    os << "|" << std::setw(11) << student.privilege;
    os << "|" << std::setw(11) << student.scholarship << "$|";
    return os;
}

std::istream &operator>>(std::istream &is, GraduateStudent &student) {
    std::cout << "Введите специальность: ";
    getline(is, student.specialty);
    std::cout << "Введите № группы: ";
    student.group = InputError::Input(100000, 999999);
    is.get();
    std::cout << "Введите ФИО студента: ";
    getline(is, student.name);
    std::cout << "Введите особые умения студента: ";
    getline(is, student.specialSkills);
    std::cout << "Введите количество публикаций: ";
    student.numberOfPublications = InputError::Input(0, 10000);
    student.scholarship = student.scholarship + 20 * student.numberOfPublications;
    std::cout << "Есть ли льготы у студента? (1. Да. 2. Нет.) ";
    student.privilege = static_cast<bool>(InputError::Input(1, 2) % 2);
    if (student.privilege) {
        student.scholarship += 250;
    }
    is.get();
    is >> dynamic_cast<Session&>(student);
    if (!student.getDebt()) {
        switch (student.getMark()) {
            case 4: case 5: case 6: {
                student.scholarship += 200;
                break;
            }
            case 7: {
                student.scholarship += 220;
                break;
            }
            case 8: {
                student.scholarship += 240;
                break;
            }
            case 9: case 10: {
                student.scholarship += 260;
                break;
            }
            default: {
                std::cout << "Ошибка! Студент без задолжностей не может иметь такой балл!" << std::endl;
                break;
            }
        }
    }
    return  is;
}

