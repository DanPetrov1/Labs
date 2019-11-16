#ifndef KURSACHKARPEICHIK_FILE_H
#define KURSACHKARPEICHIK_FILE_H

#include "List.h"
#include "Specialist.h"
#include "Supervisor.h"
#include "Trainee.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

template <class T>
class File {
public:
    File() = default;
    ~File() = default;;

    static void openUser(List<T>& list, const char *file);
    static void openSpecialist(List<T>& list, const char *file);
    static void openSupervisor(List<T>& list, const char *file);
    static void openTrainee(List<T>& list, const char *file);

    static void saveUser(List<T>& list, const char *file);
    static void saveSpecialist(List<T>& list, const char *file);
    static void saveSupervisor(List<T>& list, const char *file);
    static void saveTrainee(List<T>& list, const char *file);
};

template<class T>
void File<T>::openUser(List<T> &list, const char *file) {
    std::ifstream in;
    in.open(file);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    char BUFFER[20];
    int val3;
    while (EOF) {
        int i = 0;
        in >> BUFFER[i];
        if (!in || BUFFER[i++] == '%') {
            break;
        }
        while ((BUFFER[i] = in.get()) != '|' && BUFFER[i] != '\n') {
            i++;
        }
        BUFFER[i] = '\0';
        std::string val1(BUFFER);
        i = 0;
        while ((BUFFER[i] = in.get()) != '|' && BUFFER[i] != '\n') {
            i++;
        }
        BUFFER[i] = '\0';
        std::string val2(BUFFER);
        in >> val3;
        User user(val1, val2, val3);
        list.pushTail(user);
    }
    in.close();
}

template<class T>
void File<T>::openSpecialist(List<T> &list, const char *file) {
    std::ifstream in;
    in.open(file, std::ios::in);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    char BUFFER[50];
    char *val5 = new char[50];
    int val1, val2, val3, val4;
    while (EOF) {
        int i = 0;
        in >> BUFFER[i];
        if (!in || BUFFER[i++] == '%') {
            break;
        }
        while ((BUFFER[i] = in.get()) != '|' && BUFFER[i] != '\n') {
            i++;
        }
        BUFFER[i] = '\0';
        strcpy(val5, BUFFER);
        in.get();
        in >> val1 >> val2 >> val3 >> val4;
        Specialist specialist(val1, val2, val3, val4, val5);
        list.pushTail(specialist);
    }
    in.close();
}

template<class T>
void File<T>::openSupervisor(List<T> &list, const char *file) {
    std::ifstream in;
    in.open(file);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    char BUFFER[50];
    char *val5 = new char[50];
    int val1, val2, val3, val4, val6;
    bool val7;
    while (EOF) {
        int i = 0;
        in >> BUFFER[i];
        if (!in || BUFFER[i++] == '%') {
            break;
        }
        while ((BUFFER[i] = in.get()) != '|' && BUFFER[i] != '\n') {
            i++;
        }
        BUFFER[i] = '\0';
        strcpy(val5, BUFFER);
        in.get();
        in >> val1 >> val2 >> val3 >> val4 >> val6 >> val7;
        Supervisor supervisor(val1, val2, val3, val4, val5, val6, val7);
        list.pushTail(supervisor);
    }
    in.close();
}

template<class T>
void File<T>::openTrainee(List<T> &list, const char *file) {
    std::ifstream in;
    in.open(file, std::ios::in);
    if (!in.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    int val1, val2, val3, val4;
    while (EOF | in.failbit) {
        in >> val1;
        if (in.failbit) {
            in.clear();
            break;
        }
        in >> val2 >> val3 >> val4;
        Trainee trainee(val1, val2, val3, val4);
        list.pushTail(trainee);
        in.get();
    }
    in.close();
}

template<class T>
void File<T>::saveUser(List<T> &list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios_base::out);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getUsername() << "|" << list[i].getPassword() << "|" << list[i].isAdmin();
        on << std::endl;
    }
    on << "%";
    on.close();
}

template<class T>
void File<T>::saveSpecialist(List<T> &list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios_base::out);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getSpecialSkills() << "| " << list[i].getSalary() << " " << list[i].getBankBook() << " " <<
            list[i].getNumberOfProjects() << " " << list[i].getWorkExperience();
        on << std::endl;
    }
    on << "%";
    on.close();
}

template<class T>
void File<T>::saveSupervisor(List<T> &list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios_base::out);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getSpecialSkills() << "| " << list[i].getSalary() << " " << list[i].getBankBook() << " " <<
           list[i].getNumberOfProjects() << " " << list[i].getWorkExperience() << " " << list[i].getDepartmentNumber()
           << " " << list[i].isRetraining();
        on << std::endl;
    }
    on << "%";
    on.close();
}

template<class T>
void File<T>::saveTrainee(List<T> &list, const char *file) {
    std::ofstream on;
    on.open(file, std::ios_base::out);
    if (!on.is_open()) {
        std::cout << "Невозможно открыть файл!" << std::endl;
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        on << list[i].getSalary() << " " << list[i].getBankBook() << " " <<
           list[i].getGroup() << " " << list[i].getNumberOfCompletedTasks();
        on << std::endl;
    }
    on << "%";
    on.close();
}


#endif //KURSACHKARPEICHIK_FILE_H
