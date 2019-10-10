#include <iostream>
#include <string>
#include "MyException.h"

#ifndef SCHOLARSHIP_INPUTERROR_H
#define SCHOLARSHIP_INPUTERROR_H

class InputError : public MyException {
public:
    explicit InputError(int code = 0) : MyException(code) {};
    void errorText() override;
    static int input(int min, int max);
    static std::string inputNumber();
    static void rightNumber(std::string input) noexcept(false);
};

#endif