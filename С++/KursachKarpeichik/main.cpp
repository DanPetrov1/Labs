#include <iostream>
#include "Headers/Interface.h"
#include "Headers/Specialist.h"
#include "Windows.h"
#include "Headers/File.h"
#include "Headers/Supervisor.h"
#include "Headers/Trainee.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int select;
    User user = Interface<User>::authorization();
    if (user.getUsername().empty()) {
        return 0;
    }
    if (user.isAdmin()) {
        while (true) {
            std::cout << "Выберите данные для работы с ними:" << std::endl;
            std::cout << "1. Специалисты компании." << std::endl;
            std::cout << "2. Начальники компании." << std::endl;
            std::cout << "3. Стажёры компании." << std::endl;
            std::cout << "4. Выход." << std::endl;
            select = InputError::Input(1, 4);
            switch (select) {
                case 1: {
                    List<Specialist> list;
                    File<Specialist>::openSpecialist(list, "specialist.txt");
                    Interface<Specialist>::adminMenu(list);
                    File<Specialist>::saveSpecialist(list, "specialist.txt");
                    break;
                }
                case 2: {
                    List<Supervisor> list;
                    File<Supervisor>::openSupervisor(list, "supervisor.txt");
                    Interface<Supervisor>::adminMenu(list);
                    File<Supervisor>::saveSupervisor(list, "supervisor.txt");
                    break;
                }
                case 3: {
                    List<Trainee> list;
                    File<Trainee>::openTrainee(list, "trainee.txt");
                    Interface<Trainee>::adminMenu(list);
                    File<Trainee>::saveTrainee(list, "trainee.txt");
                    break;
                }
                case 4: {
                    return 0;
                }
            }
        }
    } else {
        while (true) {
            std::cout << "Выберите данные для работы с ними:" << std::endl;
            std::cout << "1. Специалисты компании." << std::endl;
            std::cout << "2. Начальники компании." << std::endl;
            std::cout << "3. Стажёры компании." << std::endl;
            std::cout << "4. Выход." << std::endl;
            select = InputError::Input(1, 4);
            switch (select) {
                case 1: {
                    List<Specialist> list;
                    File<Specialist>::openSpecialist(list, "specialist.txt");
                    Interface<Specialist>::menu(list);
                    File<Specialist>::saveSpecialist(list, "specialist.txt");
                    break;
                }
                case 2: {
                    List<Supervisor> list;
                    File<Supervisor>::openSupervisor(list, "supervisor.txt");
                    Interface<Supervisor>::menu(list);
                    File<Supervisor>::saveSupervisor(list, "supervisor.txt");
                    break;
                }
                case 3: {
                    List<Trainee> list;
                    File<Trainee>::openTrainee(list, "trainee.txt");
                    Interface<Trainee>::menu(list);
                    File<Trainee>::saveTrainee(list, "trainee.txt");
                    break;
                }
                case 4: {
                    return 0;
                }
            }
        }
    }
    return 0;
}