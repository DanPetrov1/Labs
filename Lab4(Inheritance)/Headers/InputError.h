//
// Created by dan on 28.10.19.
//

#ifndef LAB4_INHERITANCE__INPUTERROR_H
#define LAB4_INHERITANCE__INPUTERROR_H


#include <string>
#include "MyException.h"

class InputError : public MyException {
public:
    explicit InputError(int code = 0) : MyException(code) {};
    void errorText() override;
    static int input(int min, int max);
    static std::string inputNumber();
    static void rightNumber(std::string input) noexcept(false);
};


#endif //LAB4_INHERITANCE__INPUTERROR_H
