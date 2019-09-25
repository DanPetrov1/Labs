#include <iostream>
#include <string>
#include "MyException.h"

class InputError : public MyException {
public:
    InputError(int code = 0) : MyException(code) {};
    void ErrorText();
    static int Input(int min, int max);
    static std::string InputNumber();
    static void RightNumber(std::string input) noexcept(false);
};