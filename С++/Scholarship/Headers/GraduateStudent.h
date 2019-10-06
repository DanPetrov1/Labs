#ifndef SCHOLARSHIP_GRADUATESTUDENT_H
#define SCHOLARSHIP_GRADUATESTUDENT_H

#include "Session.h"

class GraduateStudent : public Session { //Класс студента аспирантуры
private:
    int group = 0;
    std::string specialty = "0";
    std::string name = "0";
    bool privilege = false;
    int scholarship = 0;
    int numberOfPublications = 0;
    std::string specialSkills = "0";
public:
    GraduateStudent() : Session(false, 0, "0", 0){};
    GraduateStudent(int group, const std::string &specialty, const std::string &name, bool privilege, int scholarship,
            int numberOfPublications, const std::string &specialSkills, const bool &debt, int number, std::string subjectName, int mark);
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

    static void table() {};
};


#endif //SCHOLARSHIP_GRADUATESTUDENT_H
