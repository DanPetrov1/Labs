//
// Created by danpe on 08.11.2019.
//

#include "../Headers/InputError.h"
#include <iostream>
using namespace std;

void InputError::errorText()
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
        case 4:
        {
            cout << "Вы ввели неверный набор символов!" << endl;
            break;
        }
        default:
            cout << "Повторите ввод" << endl;
            break;
    }
}
int InputError::input(int min, int max) noexcept
{
    bool flag = true;
    int value;
    do
    {
        try
        {
            cin.sync();
            cin.clear();
            rewind(stdin);
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
            rewind(stdin);
            e.errorText();
            cin.sync();
            cin.clear();
        }
        catch (...)
        {
            rewind(stdin);
            cin.sync();
            cin.clear();
            cout << "Введено некорректное значение. Необходимо ввести значение в диапазоне (" << min << "," << max << ")." << endl;
        }
    } while (!flag);
    return value;
}

void InputError::rightNumber(string input) noexcept(false) {
    cin.clear();
    rewind(stdin);
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

string InputError::inputNumber()
{
    string input;
    try
    {
        rewind(stdin);
        cin.sync();
        cin.clear();
        cin >> input;
        rightNumber(input);
    }
    catch (InputError e)
    {
        e.errorText();
        cin.clear();
        cin.sync();
        input = inputNumber();
    }
    rewind(stdin);
    return input;
}

char* InputError::inputString() {
    char input;
    char* buffer = new char[30];
    int i = 0;
    bool flag = true;
    while (flag) {
        try {
            input = cin.get();
            if (input != ' ' && input != '\n' && (input < 'a' || input > 'z') && (input < 'A' || input > 'Z') && (input < '0' || input > '9')) {
                throw (InputError(4));
            }
            if (input == '\n') {
                input = '\0';
                flag = false;
            }
            buffer[i] = input;
            i++;
        } catch (InputError e) {
            rewind(stdin);
            e.errorText();
            cin.clear();
            cin.sync();
        }
    }
    return buffer;
}
