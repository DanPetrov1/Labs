#ifndef SCHOLARSHIP_GRADUATESTUDENT_H
#define SCHOLARSHIP_GRADUATESTUDENT_H

#include "Student.h"

class GraduateStudent : public Student { //Класс студента аспирантуры
private:
    int group = 0;
    std::string specialty = "0";
    std::string name = "0";
    bool privilege = false;
    int scholarship = 0;
    int numberOfPublications = 0;
    std::string specialSkills = "0";
public:
    GraduateStudent() : Student(0, "0", "0", false, 0, false, 0, "0", 0){};
    GraduateStudent(int group, const std::string &specialty, const std::string &name, bool privilege, int scholarship,
            int numberOfPublications, const std::string &specialSkills, const bool &debt, int number, std::string subjectName, int mark);
    ~GraduateStudent() = default;

    int getNumberOfPublications() const;
    void setNumberOfPublications(int numberOfPublications);
    const std::string &getSpecialSkills() const;
    void setSpecialSkills(const std::string &specialSkills);

    friend std::ostream &operator<<(std::ostream &os, GraduateStudent &student);
    friend std::istream &operator>>(std::istream &is, GraduateStudent &student);

    static void table() {};
};


#endif //SCHOLARSHIP_GRADUATESTUDENT_H
