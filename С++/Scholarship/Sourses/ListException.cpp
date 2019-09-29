#include "../Headers/ListException.h"

void ListException::ErrorText()
{
    std::cout << "Ошибка (код " << code << "): " << std::endl;
    switch (code)
    {
        case 1:
        {
            std::cout << "Список пуст" << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "Невозможно отменить действие.";
            std::cout << " Все возможные последние действия cо студентами отменены." << std::endl;
            break;
        }
    }
}