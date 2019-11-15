#ifndef KURSACHKARPEICHIK_INTERFACE_H
#define KURSACHKARPEICHIK_INTERFACE_H

#include "List.h"
#include "Algorithm.h"
#include <iostream>
#include "InputError.h"
#include "ListException.h"

template<class T>
class Interface {
public:
    static void menu(List<T>& list);
    static void adminMenu(List<T>& list);
    static User& authorization();
};

template<class T>
void Interface<T>::menu(List<T>& list) {
    std::vector<T> ReturnPrev;
    std::vector<int> action;
    std::vector<int> place;
    int select = 0;
    do {
        system("cls");
        std::cout << "Вас приветствует система персонала компании!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Добавить специалиста в систему" << std::endl;
        std::cout << "2. Посмотреть список специалистов" << std::endl;
        std::cout << "3. Удалить последнего специалиста из системы" << std::endl;
        std::cout << "4. Изменить данные о конкретном специалисте" << std::endl;
        std::cout << "5. Отмена предыдущего действия со специалистами" << std::endl;
        std::cout << "6. Отсортировать список специалистов" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        try {
            select = InputError::Input(0, 6);
            switch (select) {
                case 1: //Добавить студента
                {
                    system("cls");
                    Algorithm<T>::add(list, ReturnPrev, action);
                    break;
                }
                case 2: //Посмотреть список студентов
                {
                    system("cls");
                    if (list.size() == 0) {
                        throw ListException(1);
                    } else {
                        list.output();
                        std::cout << std::endl;
                        system("pause");
                    }
                    break;
                }
                case 3: //Удалить последнего студента из системы
                {
                    system("cls");
                    Algorithm<T>::remove(list, ReturnPrev, action);
                    break;
                }
                case 4: //Изменить данные о конкретном студенте
                {
                    system("cls");
                    Algorithm<T>::update(list, ReturnPrev, action, place);
                    break;
                }
                case 5: //Отмена предыдущего действия со студентом
                {
                    system("cls");
                    Algorithm<T>::cancel(list, ReturnPrev, action, place);
                    break;
                }
                case 6: //Отсортировать список студентов
                {
                    system("cls");
                    Algorithm<T>::sort(list, ReturnPrev, action, place);
                    break;
                }
            }
        }
        catch (ListException e) {
            e.ErrorText();
            system("pause");
            std::cin.sync();
            std::cin.clear();
            rewind(stdin);
        }
    } while (select != 0);
}

template<class T>
User &Interface<T>::authorization() {
    int select = 0;
    User currentUser;
    do {
        system("cls");
        std::cout << "Авторизация в систему контроля рабочего персонала!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Авторизация в систему" << std::endl;
        std::cout << "2. Регистрация нового пользователя" << std::endl;
        std::cout << "3. Выход из системы" << std::endl;
        select = InputError::Input(1, 3);
        switch (select) {
            case 1: {
                currentUser = Algorithm<User>::authorization();
                if (strcmp(currentUser.getUsername(), "")) {
                    return currentUser;
                }
                break;
            }
            case 2: {
                Algorithm<User>::registration();
                break;
            }
            case 3: exit(0);
        }
    } while (select != 3);
}

template<class T>
void Interface<T>::adminMenu(List<T>& list) {

}


#endif //KURSACHKARPEICHIK_INTERFACE_H
