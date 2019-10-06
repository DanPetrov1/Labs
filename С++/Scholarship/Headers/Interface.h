#ifndef SCHOLARSHIP_INTERFACE_H
#define SCHOLARSHIP_INTERFACE_H

#include "../Headers/Student.h"
#include "../Headers/UndergraduateStudent.h"
#include "../Headers/GraduateStudent.h"
#include "../Headers/File.h"
#include "../Headers/List.h"
#include "../Headers/InputError.h"
#include "../Headers/MyException.h"
#include "../Headers/ListException.h"
#include <vector>
#include <iomanip>
#include <stdio_ext.h>

template<class T>
class Interface {
public:
    static void menu(List<T>& list);
    static void add(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action);
    static void remove(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action);
    static void update(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place);
    static void sort(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place);
    static void cancel(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place);
    static void line(int size)
    {
        std::cout << std::setfill('-') << std::setw(size) << "" << std::endl;
        std::cout << std::setfill(' ');
    }
};

template<class T>
void Interface<T>::add(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action) {
    T tmp;
    std::cin >> tmp;
    list.pushTail(tmp);
    returnPrev.insert(returnPrev.end(), tmp);
    action.insert(action.end(), 1);
}

template<class T>
void Interface<T>::remove(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action) {
    if (list.size() == 0) {
        throw ListException(1);
    } else {
        T tmp = list[list.size() - 1];
        returnPrev.insert(returnPrev.end(), tmp);
        action.insert(action.end(), 2);
        list.popTail();
    }
}

template<class T>
void Interface<T>::update(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place) {
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
}

template<class T>
void Interface<T>::sort(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place) {
    if (!list.size()) {
        throw ListException(1);
    }
    T::table();
    list.output();
    std::cout << std::endl;
    std::cout << "Выберите по какому признаку отсортировать: (1. ФИО. 2. № группы. 3. Размер стипендии.) ";
    int type = InputError::Input(1, 3);
    list.sort(type);
}

template<class T>
void Interface<T>::cancel(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place) {
    if (!action.size()) {
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
                    Interface<T>::add(list, ReturnPrev, action);
                    break;
                }
                case 2: //Посмотреть список студентов
                {
                    if (list.size() == 0) {
                        throw ListException(1);
                    } else {
                        T::table();
                        list.output();
                        std::cout << std::endl;
                    }
                    break;
                }
                case 3: //Удалить последнего студента из системы
                {
                    Interface<T>::remove(list, ReturnPrev, action);
                    break;
                }
                case 4: //Изменить данные о конкретном студенте
                {
                    Interface<T>::update(list, ReturnPrev, action, place);
                    break;
                }
                case 5: //Отмена предыдущего действия со студентом
                {
                    Interface<T>::cancel(list, ReturnPrev, action, place);
                    break;
                }
                case 6: //Отсортировать список студентов
                {
                    Interface<T>::sort(list, ReturnPrev, action, place);
                    break;
                }
            }
        }
        catch (ListException e) {
            e.ErrorText();
            std::cin.sync();
            std::cin.clear();
            __fpurge(stdin);
        }
    } while (select != 0);
}

#endif //SCHOLARSHIP_INTERFACE_H
