//
// Created by danpe on 08.11.2019.
//

#ifndef EXCEPTIONS_MYEXCEPTION_H
#define EXCEPTIONS_MYEXCEPTION_H

class MyException {
protected:
    int code;
public:
    explicit MyException(int code = 0) { this->code = code; }
    virtual void errorText(){};
};


#endif //EXCEPTIONS_MYEXCEPTION_H
