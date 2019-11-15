#include "../Headers/InputError.h"
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
            rewind(stdin);
            cin >> value;
            flag = true;
            if (!cin || cin.peek() != '\n')
            {
                flag = false;
                throw InputError(2);
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
            e.ErrorText();
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

int InputError::InputNumber()
{
    int input;
    try
    {
        rewind(stdin);
        cin.sync();
        cin.clear();
        cin >> input;
        if (!cin || cin.peek() != '\n')
        {
            throw InputError(2);
        }
    }
    catch (InputError e)
    {
        e.ErrorText();
        cin.clear();
        cin.sync();
        input = InputNumber();
    }
    rewind(stdin);
    return input;
}