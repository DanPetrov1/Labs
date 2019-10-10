#ifndef SCHOLARSHIP_UNDERGRADUATESTUDENT_H
#define SCHOLARSHIP_UNDERGRADUATESTUDENT_H

#include <ostream>
#include "Session.h"
#include "Student.h"

class UndergraduateStudent : public Student { //Класс студента магистратуры
private:
    std::string undergraduationType = "0";
public:
    UndergraduateStudent():Student(0, "0", "0", false, 0, false, 0, "0", 0){};
    UndergraduateStudent(int group, const std::string &specialty, const std::string &name, bool privilege,
            int scholarship, const std::string &undergraduationType, const bool &debt, int number,  std::string subjectName, int mark);
    ~UndergraduateStudent() = default;

    const std::string &getUndergraduationType() const;
    void setUndergraduationType(const std::string &undergraduationType);

    friend std::istream &operator>>(std::istream &is, UndergraduateStudent &student);
    friend std::ostream &operator<<(std::ostream &os, UndergraduateStudent &student);

    static void table() {};
};


#endif //SCHOLARSHIP_UNDERGRADUATESTUDENT_H
