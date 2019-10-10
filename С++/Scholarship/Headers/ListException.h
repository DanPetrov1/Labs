#ifndef SCHOLARSHIP_LISTEXCEPTION_H
#define SCHOLARSHIP_LISTEXCEPTION_H

#include "MyException.h"

class ListException : MyException {
public:
    explicit ListException(int code = 0) : MyException(code) {};
    void errorText();
};


#endif //SCHOLARSHIP_LISTEXCEPTION_H
