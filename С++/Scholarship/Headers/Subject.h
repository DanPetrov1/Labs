#ifndef SCHOLARSHIP_SUBJECT_H
#define SCHOLARSHIP_SUBJECT_H

#include <string>

class Subject {
protected:
    std::string subjectName = "0";
    int mark = 0;
public:
    Subject(std::string subjectName, int mark) : subjectName(subjectName), mark(mark){};
    ~Subject(){};

    const std::string &getSubjectName() const;

    void setSubjectName(const std::string &subjectName);

    int getMark() const;

    void setMark(int mark);

    friend std::istream& operator>>(std::istream& is, Subject& sub);
    friend std::ostream& operator<<(std::ostream& os, Subject& sub);
};


#endif //SCHOLARSHIP_SUBJECT_H
