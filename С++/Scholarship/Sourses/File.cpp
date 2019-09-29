#include "../Headers/File.h"
#include "../Headers/Student.h"
#include "../Headers/UndergraduateStudent.h"
#include "../Headers/GraduateStudent.h"
#include <iostream>
#include <fstream>

template<class T>
void File<T>::openStudent(List<T>& list, const char *file) {
    std::ifstream in;
    in.open(file, std::ios::in);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    while (true) {
        std::string val1;
        int val2;
        std::string val3;
        bool val4;
        int val5;
        bool val6;
        int val7;
        in >> val1 >> val2 >> val3 >> val4 >> val5 >> val6 >> val7;
        if (val1 == "%") break;
        Student tmp(val2, val1, val3, val4, val5, val6, val7);
        list.pushTail(tmp);
    }
    in.close();
}

template<class T>
void File<T>::openUndergraduate(List<T>& list, const char *file) {
    std::ifstream in;
    in.open(file, std::ios::in);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    while (true) {
        std::string val1;
        int val2;
        std::string val3;
        bool val4;
        int val5;
        std::string val6;
        bool val7;
        int val8;
        in >> val1 >> val2 >> val3 >> val4 >> val5 >> val6 >> val7 >> val8;
        if (val1 == "%") break;
        UndergraduateStudent tmp(val2, val1, val3, val4, val5, val6, val7, val8);
        list.pushTail(tmp);
    }
    in.close();
}

template<class T>
void File<T>::openGraduate(List<T>& list, const char *file) {
    std::ifstream in;
    in.open(file, std::ios::in);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    while (true) {
        std::string val1;
        int val2;
        std::string val3;
        bool val4;
        int val5;
        int val6;
        std::string val7;
        bool val8;
        int val9;
        in >> val1 >> val2 >> val3 >> val4 >> val5 >> val6 >> val7 >> val8 >> val9;
        if (val1 == "%") break;
        GraduateStudent tmp(val2, val1, val3, val4, val5, val6, val7, val8, val9);
        list.pushTail(tmp);
    }
    in.close();
}

template <class T>
void File<T>::saveStudent(List<T>& list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios::in | std::ios_base::trunc);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getSpecialty() << " " << list[i].getGroup() << " " << list[i].getName() << " " <<
            list[i].getPrivilege() << " " << list[i].getScholarship() << " " << list[i].getUdergraduationType() << " "
            << list[i].getDebt() << " " << list[i].getMark();
        on << std::endl;
    }
    on << "%";
    on.close();
}

template<class T>
void File<T>::saveUndergraduate(List<T>& list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios::in | std::ios_base::trunc);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getSpecialty() << " " << list[i].getGroup() << " " << list[i].getName() << " " <<
        list[i].getPrivilege() << " " << list[i].getScholarship() << " " << list[i].getNumberOfPublications() << " "
        << list[i].getSpecialSkills() << " " << list[i].getDebt() << " " << list[i].getMark();
        on << std::endl;
    }
    on << "%";
    on.close();
}

template<class T>
void File<T>::saveGraduate(List<T>& list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios::in | std::ios_base::trunc);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getSpecialty() << " " << list[i].getGroup() << " " << list[i].getName() << " " <<
           list[i].getPrivilege() << " " << list[i].getScholarship() << " " << list[i].getDebt() << " " <<
           list[i].getMark();
        on << std::endl;
    }
    on << "%";
    on.close();
}