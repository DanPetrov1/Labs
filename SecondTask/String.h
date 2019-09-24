#include <iostream>

class String {
private:
    char*str = nullptr;
public:
    String();
    String(char*str);
    String(const String&);

    ~String();

    String& operator=(const String&);
    friend String& operator+(String&, String&);
    String& operator+=(const String&);

    friend String& operator++(String&);
    friend String& operator--(String&);
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);
    friend bool operator>(const String&, const String&);
    friend bool operator>=(const String&, const String&);
    friend bool operator<(const String&, const String&);
    friend bool operator<=(const String&, const String&);
    char& operator[](const int index);
    char& operator()(const int index);
    String operator()(const int begin, const int end);

    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::istream& operator>>(std::istream&, String&);
};

int size(char*);
void strCpy(char*, char*);
bool strCmp(char*, char*);