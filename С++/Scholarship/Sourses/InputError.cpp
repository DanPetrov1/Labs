#include "../Headers/InputError.h"
#include <stdio_ext.h>
using namespace std;

void InputError::ErrorText()
{
    cout << "Ошибка ввода (код " << this->code << "): ";
    switch (this->code)
    {
        case 1:
        {
            cout << "Введён недопустимый символ." << endl;
            cout << "Ввод любых символов, кроме цифр, запрещён." << endl;
            break;
        }
        case 2:
        {
            cout << "Введено некорректное число символов!" << endl;
            cout << "Необходимо ввести 6 цифр." << endl;
            break;
        }
        case 3:
        {
            cout << "Вы ввели символы вместо числа либо превышен предел по вводу чисел!"  << endl;
            break;
        }
        default:
            cout << "Повторите ввод" << endl;
            break;
    }
}
int InputError::Input(int min, int max)
{
    bool flag = true;
    int value;
    do
    {
        try
        {
            cin.sync();
            cin.clear();
            __fpurge(stdin);
            cin >> value;
            flag = true;
            if (!cin || cin.peek() != '\n')
            {
                flag = false;
                throw InputError(3);
            }
            if (value<min || value>max)
            {
                flag = false;
                throw "Limit error";
            }
        }
        catch (InputError e)
        {
            __fpurge(stdin);
            e.ErrorText();
            cin.sync();
            cin.clear();
        }
        catch (...)
        {
            __fpurge(stdin);
            cin.sync();
            cin.clear();
            cout << "Введено некорректное значение. Необходимо ввести значение в диапазоне (" << min << "," << max << ")." << endl;
        }
    } while (!flag);
    return value;
}
void InputError::RightNumber(string input) noexcept(false) {
    cin.clear();
    __fpurge(stdin);
    int len = input.length();
    int i = 0;
    while(i<len)
    {
        if (input[i] < '0' || input[i] >'9')
        {
            throw InputError(1);
        }
        i++;
    }
    if (len != 6)
    {
        throw InputError(2);
    }
}
string InputError::InputNumber()
{
    string input;
    try
    {
        __fpurge(stdin);
        cin.sync();
        cin.clear();
        cin >> input;
        RightNumber(input);
    }
    catch (InputError e)
    {
        e.ErrorText();
        cin.clear();
        cin.sync();
        input = InputNumber();
    }
    __fpurge(stdin);
    return input;
}
