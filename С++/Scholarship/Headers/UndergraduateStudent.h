#ifndef SCHOLARSHIP_UNDERGRADUATESTUDENT_H
#define SCHOLARSHIP_UNDERGRADUATESTUDENT_H

#include <ostream>
#include "Session.h"

class UndergraduateStudent : public Session { //Класс студента магистратуры
private:
    int group;
    std::string specialty;
    std::string name;
    bool privilege;
    int scholarship;
    std::string undergraduationType;
public:
    UndergraduateStudent(int group, const std::string &specialty, const std::string &name, bool privilege,
            int scholarship, const std::string &undergraduationType, const bool &debt, int mark);
    ~UndergraduateStudent() = default;

    int getGroup() const;
    void setGroup(int group);
    const std::string &getSpecialty() const;
    void setSpecialty(const std::string &specialty);
    const std::string &getName() const;
    void setName(const std::string &name);
    bool isPrivilege() const;
    void setPrivilege(bool privilege);
    int getScholarship() const;
    void setScholarship(int scholarship);
    const std::string &getUndergraduationType() const;
    void setUndergraduationType(const std::string &undergraduationType);

    friend std::istream &operator>>(std::istream &is, UndergraduateStudent &student);
    friend std::ostream &operator<<(std::ostream &os, UndergraduateStudent &student);
};


#endif //SCHOLARSHIP_UNDERGRADUATESTUDENT_H
