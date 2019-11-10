//
// Created by danpe on 08.11.2019.
//

#ifndef EXCEPTIONS_PERSON_H
#define EXCEPTIONS_PERSON_H

#include <string>
#include <iostream>

class Person {
protected:
    char *surname;
    char *name;
    int birthdayYear = 0;
public:
    Person(char *surname = nullptr, char *name = nullptr, int birthdayYear = 0) : surname(surname),
        name(name), birthdayYear(birthdayYear){ this->surname = new char[1]; this->name = new char[1]; }
    char *getSurname() const;
    char *getName() const;
    int getBirthdayYear() const;

    void setSurname(char *surname);
    void setName(char *name);
    void setBirthdayYear(int birthdayYear);

    friend std::istream &operator>>(std::istream &is, Person& person);
    friend std::ostream &operator<<(std::ostream &os, const Person &person);

    virtual void table();
};


#endif //EXCEPTIONS_PERSON_H
