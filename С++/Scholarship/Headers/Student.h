#include <utility>

#include <iostream>
#include <string>
#include "Session.h"

#ifndef SCHOLARSHIP_STUDENT_H
#define SCHOLARSHIP_STUDENT_H

class Student : public Session {
private:
    int group = 0;
    std::string specialty = "0";
    std::string name = "0";
    bool privilege = false;
    int scholarship = 0;
public:
    Student() : Session(false, 0, "0", 0){};
    Student(int group, const std::string &specialty, const std::string &name, bool privilege, int scholarship,
            const bool &debt, int number, std::string subjectName, int mark) : Session(debt, number, subjectName, mark),
            group(group), specialty(specialty), name(name), privilege(privilege), scholarship(scholarship){}
    ~Student() = default;;

    int getGroup() const;
    void setGroup(int group);
    const std::string &getName() const;
    void setName(const std::string &name);
    bool isPrivilege() const;
    void setPrivilege(bool privilege);
    int getScholarship() const;
    void setScholarship(int scholarship);
    const std::string &getSpecialty() const;
    void setSpecialty(const std::string &specialty);

    friend std::istream& operator >> (std::istream& is, Student& obj);
    friend std::ostream& operator << (std::ostream& os, Student& obj);

    static void table();
};

#endif