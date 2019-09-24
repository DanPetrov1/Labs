#include <iostream>
#include "String.h"

String::String() {
    this->str = new char(1);
    this->str[0] = '\0';
}

String::String(char *str) {
    this->str = new char[size(str) + 1];
    strCpy(this->str, str);
}

String::String(const String &obj) {
    this->str = new char[size(obj.str) + 1];
    strCpy(this->str, obj.str);
}

String::~String() {
    if (size(this->str) > 0)
        delete(this->str);
}

String &String::operator=(const String &obj) {
    if (this != &obj) {
        delete(this->str);
        this->str = new char[size(obj.str)+1];
        strCpy(this->str, obj.str);
    }
    return *this;
}

String& String::operator+=(const String& obj) {
    int stringSize = size(this->str) + size(obj.str);
    char* newString = new char[stringSize+1];
    for (int i = 0; i < size(this->str); i++) {
        newString[i] = this->str[i];
    }
    for (int i = size(this->str), j = 0; i <= stringSize; i++, j++) {
        newString[i] = obj.str[j];
    }
    delete this->str;
    this->str = newString;
    return *this;
}

String& operator+(String& obj1, String& obj2) {
    return obj1 += obj2;
}

bool operator==(const String& obj1, const String& obj2) {
    return strCmp(obj1.str, obj2.str);
}

bool operator!=(const String& obj1, const String& obj2) {
    return !(strCmp(obj1.str, obj2.str));
}

bool operator>(const String& obj1, const String& obj2) {
    return size(obj1.str) > size(obj2.str);
}

bool operator>=(const String& obj1, const String& obj2) {
    return size(obj1.str) >= size(obj2.str);
}

bool operator<(const String& obj1, const String& obj2) {
    return size(obj1.str) < size(obj2.str);
}

bool operator<=(const String& obj1, const String& obj2) {
    return size(obj1.str) <= size(obj2.str);
}

std::ostream& operator<<(std::ostream& os, const String& obj) {
    os << obj.str << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, String& obj) {
    char *BUFFER = new char[2048];
    is.getline(BUFFER, 2048);
    obj.str = BUFFER;
    return is;
}

String& operator++(String &my_str) {
    for(int i = 0; i < size(my_str.str); i++)
        my_str.str[i]++;
    return my_str;
}

String& operator--(String &my_str) {
    for(int i = 0; i < size(my_str.str); i++)
        my_str.str[i]--;
    return my_str;
}

char &String::operator[](const int index) {
    return this->str[index - 1];
}

char &String::operator()(const int index) {
    return this->str[index - 1];
}

String String::operator()(const int begin, const int end) {
    String substring(*this);
    substring.str = new char[end - begin + 1];
    for (int i = 0; i < end - begin; ++i) {
        substring.str[i] = (*this)[begin + i];
    }
    substring.str[end - begin] = '\0';
    return substring;
}

int size(char* str) {
    int size = 0;
    for (; str[size] != '\0'; size++);
    return size;
}

void strCpy(char* obj1, char* obj2) {
    for (int i = 0; i < size(obj2) && obj1[i]; i++)
        obj1[i] = obj2[i];
    obj1[size(obj2)] = '\0';
}

bool strCmp(char* obj1, char* obj2)
{
    int i = 0;
    for (; obj1[i] == obj2[i] && i < size(obj2); i++);
    return i == size(obj1);
}