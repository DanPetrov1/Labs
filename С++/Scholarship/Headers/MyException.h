#include <iostream>

class MyException {
protected:
    int code;
public:
    MyException(int code = 0) { this->code = code; }
    virtual void ErrorText(){};
};