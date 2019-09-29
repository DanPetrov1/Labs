#include "../Headers/Interface.h"
#include "stdio_ext.h"
#include "../Headers/ListException.h"

template<class T>
void Interface<T>::add(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action) {
    system("cls");
    T tmp;
    std::cin >> tmp;
    list.pushTail(tmp);
    returnPrev.insert(returnPrev.end(), tmp);
    action.insert(action.end(), 1);
    system("pause");
}

template<class T>
void Interface<T>::remove(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action) {
    system("cls");
    if (list.size() == 0) {
        throw ListException(1);
    } else {
        T tmp = list[list.size() - 1];
        returnPrev.insert(returnPrev.end(), tmp);
        action.insert(action.end(), 2);
        list.popTail();
    }
    system("pause");
}

template<class T>
void Interface<T>::update(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place) {
    system("cls");
    if (!list.size()) {
        throw ListException(1);
    }
    T::table();
    list.output();
    std::cout << std::endl;
    std::cout << "Введите номер изменяемого студента : ";
    int tempNum = InputError::Input(1, list.size());
    T tmp;
    std::cin >> tmp;
    returnPrev.insert(returnPrev.end(), list[tempNum - 1]);
    action.insert(action.end(), 3);
    place.insert(place.end(), tempNum);
    list[tempNum - 1] = tmp;
    system("pause");
}

template<class T>
void Interface<T>::sort(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place) {
    system("cls");
    if (!list.size()) {
        throw ListException(1);
    }
    T::table();
    list.output();
    std::cout << std::endl;
    std::cout << "Выберите по какому признаку отсортировать: ";
    int tempNum = InputError::Input(1, list.size());

}

template<class T>
void Interface<T>::cancel(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place) {
    if (!action.size()) {
        system("cls");
        throw ListException(2);
    }
    switch (action.back()) {
        case 1: {
            list.popTail();
            action.erase(action.end() - 1);
            returnPrev.erase(returnPrev.end() - 1);
            break;
        }
        case 2: {
            list.pushTail(returnPrev.back());
            action.erase(action.end() - 1);
            returnPrev.erase(returnPrev.end() - 1);
            break;
        }
        case 3: {
            list[place.back() - 1] = returnPrev.back();
            place.erase(place.end() - 1);
            action.erase(action.end() - 1);
            returnPrev.erase(returnPrev.end() - 1);
            break;
        }
    }
}

template<class T>
void Interface<T>::menu(List<T>& list) {
    std::vector<T> ReturnPrev;
    std::vector<int> action;
    std::vector<int> place;
    int select = 0;
    do {
        system("cls");
        std::cout << "Вас приветствует система университета по начислению стипендии!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Добавить студента в систему" << std::endl;
        std::cout << "2. Посмотреть список студентов" << std::endl;
        std::cout << "3. Удалить последнего студента из системы" << std::endl;
        std::cout << "4. Изменить данные о конкретном студенте" << std::endl;
        std::cout << "5. Отмена предыдущего действия со студентом" << std::endl;
        std::cout << "6. Отсортировать список студентов" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        try {
            select = InputError::Input(0, 6);
            switch (select) {
                case 1: //Добавить студента
                {
                    system("cls");
                    Interface<T>::add(list, ReturnPrev, action);
                    break;
                }
                case 2: //Посмотреть список студентов
                {
                    system("cls");
                    if (list.size() == 0) {
                        throw ListException(1);
                    } else {
                        T::table();
                        list.output();
                        std::cout << std::endl;
                        system("pause");
                    }
                    break;
                }
                case 3: //Удалить последнего студента из системы
                {
                    system("cls");
                    Interface<T>::remove(list, ReturnPrev, action);
                    break;
                }
                case 4: //Изменить данные о конкретном студенте
                {
                    system("cls");
                    Interface<T>::update(list, ReturnPrev, action, place);
                    break;
                }
                case 5: //Отмена предыдущего действия со студентом
                {
                    system("cls");
                    Interface<T>::cancel(list, ReturnPrev, action, place);
                    break;
                }
                case 6: //Отсортировать список студентов
                {
                    system("cls");
                    Interface<T>::sort(list, ReturnPrev, action, place);
                    break;
                }
            }
        }
        catch (ListException e) {
            e.ErrorText();
            system("pause");
            std::cin.sync();
            std::cin.clear();
            __fpurge(stdin);
        }
    } while (select != 0);
}