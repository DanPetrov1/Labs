//
// Created by danpe on 08.11.2019.
//

#ifndef EXCEPTIONS_INPUTERROR_H
#define EXCEPTIONS_INPUTERROR_H

#include <string>
#include "MyException.h"

class InputError : public MyException {
public:
    explicit InputError(int code = 0) : MyException(code) {};
    void errorText() override;
    static int input(int min, int max) throw();
    static std::string inputNumber();
    static void rightNumber(std::string input) noexcept(false);
    static char* inputString();
};


#endif //EXCEPTIONS_INPUTERROR_H
