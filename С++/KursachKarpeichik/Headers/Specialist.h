#ifndef KURSACHKARPEICHIK_SPECIALIST_H
#define KURSACHKARPEICHIK_SPECIALIST_H


#include <ostream>
#include "Salary.h"

class Specialist : public Salary {
protected:
    int numberOfProjects;
    int workExperience;
    char specialSkills[50];
public:
    Specialist(int salary = 0, int bankBook = 0, int numberOfProjects = 0, int workExperience = 0,
            char *specialSkills = "");

    int getNumberOfProjects() const;
    void setNumberOfProjects(int numberOfProjects);
    int getWorkExperience() const;
    void setWorkExperience(int workExperience);
    const char* getSpecialSkills() const;
    void setSpecialSkills(const char *specialSkills);

    friend std::istream &operator>>(std::istream &is, Specialist &specialist);
    friend std::ostream &operator<<(std::ostream &os, const Specialist &specialist);
};


#endif //KURSACHKARPEICHIK_SPECIALIST_H
