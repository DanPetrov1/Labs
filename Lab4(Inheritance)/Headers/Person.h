//
// Created by dan on 18.10.19.
//

#ifndef LAB4_INHERITANCE__PERSON_H
#define LAB4_INHERITANCE__PERSON_H

#include <string>
#include <iostream>

class Person {
protected:
    std::string surname = "";
    std::string name = "";
    int birthdayYear = 0;
public:
    Person(std::string surname = "", std::string name = "", int birthdayYear = 0) : surname(surname),
                                                    name(name), birthdayYear(birthdayYear){}
    const std::string& getSurname() const;
    const std::string& getName() const;
    int getBirthdayYear() const;

    void setSurname(const std::string& surname);
    void setName(const std::string& name);
    void setBirthdayYear(int birthdayYear);

    friend std::istream &operator>>(std::istream &is, Person& person);
    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};


#endif //LAB4_INHERITANCE__PERSON_H
