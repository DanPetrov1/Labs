#include <iostream>
#include "../Headers/Student.h"
#include "../Headers/List.h"
#include "../Headers/UndergraduateStudent.h"
#include "../Headers/GraduateStudent.h"
#include "../Headers/File.h"
#include "../Headers/InputError.h"
#include "../Headers/Interface.h"

int main() {
    List<Student> students;
    List<UndergraduateStudent> undergraduateStudents;
    List<GraduateStudent> graduateStudents;
    File<Student> fs;
    File<UndergraduateStudent> fus;
    File<GraduateStudent> fgs;
    int select = 0;
    std::cout << "Вас приветствует информационная система университета!" << std::endl;
    std::cout << "Выберите тип студентов, с которыми хотите работать : " << std::endl;
    std::cout << "1. Студенты бакалавриата" << std::endl;
    std::cout << "2. Студенты магистратуры" << std::endl;
    std::cout << "3. Студенты аспирантуры" << std::endl;
    std::cout << "0. Выход из программы" << std::endl;
    select = InputError::Input(0, 3);
    switch (select) {
        case 1: //Работа с обычными студентами
        {
            fs.openStudent(students, "students.txt");
            Interface<Student>::menu(students);
            fs.saveStudent(students, "students.txt");
            break;
        }
        case 2: //Работа со студентами магистратуры
        {
            fus.openUndergraduate(undergraduateStudents, "undergraduateStudents.txt");
            Interface<UndergraduateStudent>::menu(undergraduateStudents);
            fus.saveUndergraduate(undergraduateStudents, "undergraduateStudents.txt");
            break;
        }
        case 3: //Работа со студентами аспирантуры
        {
            fgs.openGraduate(graduateStudents, "graduateStudents.txt");
            Interface<GraduateStudent>::menu(graduateStudents);
            fgs.saveGraduate(graduateStudents, "graduateStudents.txt");
            break;
        }
    }
    return 0;
}