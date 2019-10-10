#include <iomanip>
#include "../Headers/UndergraduateStudent.h"
#include "../Headers/InputError.h"

UndergraduateStudent::UndergraduateStudent(int group, const std::string &specialty, const std::string &name,
                                                bool privilege, int scholarship, const std::string &undergraduationType,
                                                const bool &debt, int number, std::string subjectName, int mark) :
                                                                Student(group, specialty, name, privilege, scholarship,
                                                                        debt, number, subjectName, mark),
                                                                                     undergraduationType(
                                                                                             undergraduationType) {}

const std::string &UndergraduateStudent::getUndergraduationType() const { return this->undergraduationType; }

void UndergraduateStudent::setUndergraduationType(const std::string &undergraduationType) {
    this->undergraduationType = undergraduationType;
}

std::ostream &operator<<(std::ostream &os, UndergraduateStudent &student) {
    os << dynamic_cast<Session&>(student);
    os << "|" << std::setw(15) << student.undergraduationType;
    return os;
}

std::istream &operator>>(std::istream &is, UndergraduateStudent &student) {
    is.get();
    std::cout << "Введите специальность: ";
    getline(is, student.specialty);
    std::cout << "Введите № группы: ";
    student.group = InputError::input(100000, 999999);
    is.get();
    std::cout << "Введите ФИО студента: ";
    getline(is, student.name);
    std::cout << "Введите тип магистратуры: 1. Бюджет очная. 2. Платная очная. 3. Платная заочная. ";
    int type = InputError::input(1, 3);
    switch (type) {
        case 1:
            student.undergraduationType = "Бюджет очная";
            break;
        case 2:
            student.undergraduationType = "Платная очная";
            break;
        case 3:
            student.undergraduationType = "Платная заочная";
            break;
        default: {
            std::cout << "Ошибка! Неправильный выбор!" << std::endl;
            student.undergraduationType = "Не выбран.";
        }
    }
    std::cout << "Есть ли льготы у студента? (1. Да. 2. Нет.) ";
    student.privilege = static_cast<bool>(InputError::input(1, 2) % 2);
    if (student.privilege) {
        student.scholarship += 150;
    }
    is.get();
    is >> dynamic_cast<Session&>(student);
    if (!student.getDebt() && type == 1) {
        switch (student.getMark()) {
            case 4: case 5: case 6: {
                student.scholarship += 150;
                break;
            }
            case 7: {
                student.scholarship += 170;
                break;
            }
            case 8: {
                student.scholarship += 190;
                break;
            }
            case 9: case 10: {
                student.scholarship += 210;
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


