#include <iostream>

#ifndef SCHOLARSHIP_MYEXCEPTION_H
#define SCHOLARSHIP_MYEXCEPTION_H

class MyException {
protected:
    int code;
public:
    explicit MyException(int code = 0) { this->code = code; }
    virtual void ErrorText(){};
};

#endif