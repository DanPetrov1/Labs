#ifndef SCHOLARSHIP_GRADUATESTUDENT_H
#define SCHOLARSHIP_GRADUATESTUDENT_H

#include "Session.h"

class GraduateStudent : public Session { //Класс студента аспирантуры
private:
    int group;
    std::string specialty;
    std::string name;
    bool privilege;
    int scholarship;
    int numberOfPublications;
    std::string specialSkills;
public:
    GraduateStudent(int group, const std::string &specialty, const std::string &name, bool privilege, int scholarship,
            int numberOfPublications, const std::string &specialSkills, const bool &debt, int mark);
    ~GraduateStudent() = default;

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
    int getNumberOfPublications() const;
    void setNumberOfPublications(int numberOfPublications);
    const std::string &getSpecialSkills() const;
    void setSpecialSkills(const std::string &specialSkills);

    friend std::ostream &operator<<(std::ostream &os, GraduateStudent &student);
    friend std::istream &operator>>(std::istream &is, GraduateStudent &student);
};


#endif //SCHOLARSHIP_GRADUATESTUDENT_H
