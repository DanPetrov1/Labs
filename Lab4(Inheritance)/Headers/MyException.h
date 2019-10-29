//
// Created by dan on 28.10.19.
//

#ifndef LAB4_INHERITANCE__MYEXCEPTION_H
#define LAB4_INHERITANCE__MYEXCEPTION_H


class MyException {
protected:
    int code;
public:
    explicit MyException(int code = 0) { this->code = code; }
    virtual void errorText(){};
};


#endif //LAB4_INHERITANCE__MYEXCEPTION_H
