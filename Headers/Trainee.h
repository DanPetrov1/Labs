#ifndef KURSACHKARPEICHIK_TRAINEE_H
#define KURSACHKARPEICHIK_TRAINEE_H


#include <ostream>
#include "Salary.h"

class Trainee : public Salary {
private:
    int group;
    int numberOfCompletedTasks;
public:
    Trainee(int salary = 0, int bankBook = 0, int group = 0, int numberOfCompletedTasks = 0);

    int getGroup() const;
    void setGroup(int group);
    int getNumberOfCompletedTasks() const;
    void setNumberOfCompletedTasks(int numberOfCompletedTasks);

    friend std::istream &operator>>(std::istream &is, Trainee &trainee);
    friend std::ostream &operator<<(std::ostream &os, const Trainee &trainee);
};


#endif //KURSACHKARPEICHIK_TRAINEE_H
