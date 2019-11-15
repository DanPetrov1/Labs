#ifndef KURSACHKARPEICHIK_INPUTERROR_H
#define KURSACHKARPEICHIK_INPUTERROR_H

#include <iostream>
#include <string>
#include "MyException.h"

class InputError : public MyException {
public:
    InputError(int code = 0) : MyException(code) {};
    void ErrorText() override;
    static int Input(int min, int max);
    static int InputNumber();
};

#endif //KURSACHKARPEICHIK_INPUTERROR_H
