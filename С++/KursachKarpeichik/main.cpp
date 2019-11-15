#include <iostream>
#include "Headers/Interface.h"
#include "Headers/Specialist.h"
#include "Windows.h"
#include "Headers/File.h"
#include "Headers/Supervisor.h"
#include "Headers/Trainee.h"

int main() {
    system("chcp 65001");
    int select;
    User user = Interface<User>::authorization();
    if (!strcmp(user.getUsername(), "")) {
        return 0;
    }
    if (user.isAdmin()) {
        while (true) {
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
                    File<Trainee>::openSupervisor(list, "trainee.txt");
                    Interface<Trainee>::adminMenu(list);
                    File<Trainee>::saveSupervisor(list, "trainee.txt");
                    break;
                }
                case 4: {
                    return 0;
                }
            }
        }
    } else {
        while (true) {
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
                    File<Trainee>::openSupervisor(list, "trainee.txt");
                    Interface<Trainee>::adminMenu(list);
                    File<Trainee>::saveSupervisor(list, "trainee.txt");
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