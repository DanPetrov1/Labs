#ifndef SCHOLARSHIP_FILE_H
#define SCHOLARSHIP_FILE_H

#include "List.h"
#include <fstream>
#include <iostream>

template <class T>
class File {
public:
    File() = default;
    ~File() = default;;

    void openStudent(List<T>& list, const char *file);
    void openUndergraduate(List<T>& list, const char *file);
    void openGraduate(List<T>& list, const char *file);

    void saveStudent(List<T>& list, const char *file);
    void saveUndergraduate(List<T>& list, const char *file);
    void saveGraduate(List<T>& list, const char *file);
};

template<class T>
void File<T>::openStudent(List<T>& list, const char *file) {
    std::ifstream in;
    in.open(file, std::ios_base::in);
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
        std::string val8;
        int val9;
        getline(in, val1);
        if (val1.empty() || val1 == "%") break;
        in >> val2;
        in.get();
        getline(in, val3);
        in >> val4;
        in >> val5;
        in >> val6;
        in >> val7;
        in.get();
        getline(in, val8);
        in >> val9;
        Student tmp(val2, val1, val3, val4, val5, val6, val7, val8, val9);
        list.pushTail(tmp);
        in.get();
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
        std::string val9;
        int val10;
        getline(in, val1);
        if (val1 == "%" || val1.empty()) break;
        in  >> val2;
        in.get();
        getline(in, val3);
        in >> val4 >> val5;
        in.get();
        getline(in, val6);
        in >> val7 >> val8;
        in.get();
        getline(in, val9);
        in >> val10;
        UndergraduateStudent tmp(val2, val1, val3, val4, val5, val6, val7, val8, val9, val10);
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
        std::string val10;
        int val11;
        getline(in, val1);
        if (val1 == "%" || val1.empty()) break;
        in >> val2;
        in.get();
        getline(in, val3);
        in >> val4 >> val5 >> val6;
        in.get();
        getline(in, val7);
        in >> val8 >> val9;
        in.get();
        getline(in, val10);
        in >> val11;
        GraduateStudent tmp(val2, val1, val3, val4, val5, val6, val7, val8, val9, val10, val11);
        list.pushTail(tmp);
    }
    in.close();
}

template <class T>
void File<T>::saveUndergraduate(List<T>& list, const char *file) {
    std::ofstream on(file);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getSpecialty() << std::endl << list[i].getGroup() << std::endl << list[i].getName() << std::endl <<
           list[i].isPrivilege() << std::endl << list[i].getScholarship() << std::endl << list[i].getUndergraduationType() << std::endl
           << list[i].getDebt() << std::endl << list[i].getNumber() << std::endl << list[i].getSubjectName() << std::endl << list[i].getMark();
        on << std::endl;
    }
    on << "%";
    on.close();
}

template<class T>
void File<T>::saveGraduate(List<T>& list, const char *file) {
    std::ofstream on(file);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getSpecialty() << std::endl << list[i].getGroup() << std::endl << list[i].getName() << std::endl <<
           list[i].isPrivilege() << std::endl << list[i].getScholarship() << std::endl << list[i].getNumberOfPublications() << std::endl
           << list[i].getSpecialSkills() << std::endl << list[i].getDebt() << std::endl << list[i].getNumber()
                << std::endl << list[i].getSubjectName() << std::endl << list[i].getMark();
        on << std::endl;
    }
    on << "%";
    on.close();
}

template<class T>
void File<T>::saveStudent(List<T>& list, const char *file) {
    std::ofstream on(file);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getSpecialty() << std::endl << list[i].getGroup() << std::endl << list[i].getName() << std::endl <<
           list[i].isPrivilege() << std::endl << list[i].getScholarship() << std::endl << list[i].getDebt() << std::endl <<
           list[i].getNumber() << std::endl << list[i].getSubjectName() << std::endl << list[i].getMark();
        on << std::endl;
    }
    on << "%";
    on.close();
}

#endif //SCHOLARSHIP_FILE_H
