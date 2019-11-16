#ifndef KURSACHKARPEICHIK_SUPERVISOR_H
#define KURSACHKARPEICHIK_SUPERVISOR_H


#include <ostream>
#include "Specialist.h"

class Supervisor : public Specialist {
private:
    int departmentNumber;
    bool retraining;
public:
    Supervisor(int salary = 0, int bankBook = 0, int numberOfProjects = 0, int workExperience = 0,
               char *specialSkills = "", int departmentNumber = 0, bool retraining = false);

    int getDepartmentNumber() const;
    void setDepartmentNumber(int departmentNumber);
    bool isRetraining() const;
    void setRetraining(bool retraining);

    friend std::istream &operator>>(std::istream &is, Supervisor &supervisor);
    friend std::ostream &operator<<(std::ostream &os, const Supervisor &supervisor);
};


#endif //KURSACHKARPEICHIK_SUPERVISOR_H
