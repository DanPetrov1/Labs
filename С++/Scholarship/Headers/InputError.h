#include <iostream>
#include <string>
#include "MyException.h"

#ifndef SCHOLARSHIP_INPUTERROR_H
#define SCHOLARSHIP_INPUTERROR_H

class InputError : public MyException {
public:
    explicit InputError(int code = 0) : MyException(code) {};
    void ErrorText() override;
    static int Input(int min, int max);
    static std::string InputNumber();
    static void RightNumber(std::string input) noexcept(false);
};

#endif