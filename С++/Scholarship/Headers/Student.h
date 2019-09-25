#include <iostream>
#include <string>
#include "Session.h"

class Student : public Session {
private:
    int group;
    std::string specialty;
    std::string name;
    bool privilege;
    int scholarship;
public:
    const std::string &getSpecialty() const;
    void setSpecialty(const std::string &specialty);
    Student(int group = 0, const std::string specialty = "0", const std::string &name = "0", bool privilege = false, int scholarship = 0,
            bool debt = false, int mark = 0) : Session(debt, mark),
            group(group), specialty(specialty), name(name), privilege(privilege), scholarship(scholarship){}
    Student(const Student&);
    ~Student(){};

    int getGroup() const;
    void setGroup(int group);
    const std::string &getName() const;
    void setName(const std::string &name);
    bool isPrivilege() const;
    void setPrivilege(bool privilege);
    int getScholarship() const;
    void setScholarship(int scholarship);

    friend std::istream& operator >> (std::istream& is, Student& obj);
    friend std::ostream& operator << (std::ostream& os, Student& obj);
};