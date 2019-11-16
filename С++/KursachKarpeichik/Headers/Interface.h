#ifndef KURSACHKARPEICHIK_INTERFACE_H
#define KURSACHKARPEICHIK_INTERFACE_H

#include "List.h"
#include "Algorithm.h"
#include <iostream>
#include <string>
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
        //system("cls");
        std::cout << "Вас приветствует система персонала компании!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Добавить сотрудника в систему" << std::endl;
        std::cout << "2. Посмотреть список сотрудников" << std::endl;
        std::cout << "3. Удалить последнего сотрудника из системы" << std::endl;
        std::cout << "4. Изменить данные о конкретном сотруднике" << std::endl;
        std::cout << "5. Отмена предыдущего действия с сотрудниками" << std::endl;
        std::cout << "6. Отсортировать список сотрудников" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        try {
            select = InputError::Input(0, 6);
            switch (select) {
                case 1:
                {
                    //system("cls");
                    Algorithm<T>::add(list, ReturnPrev, action);
                    break;
                }
                case 2:
                {
                    //system("cls");
                    if (list.size() == 0) {
                        throw ListException(1);
                    } else {
                        list.output();
                        std::cout << std::endl;
                        system("pause");
                    }
                    break;
                }
                case 3:
                {
                    //system("cls");
                    Algorithm<T>::remove(list, ReturnPrev, action);
                    break;
                }
                case 4:
                {
                    //system("cls");
                    Algorithm<T>::update(list, ReturnPrev, action, place);
                    break;
                }
                case 5:
                {
                    //system("cls");
                    Algorithm<T>::cancel(list, ReturnPrev, action, place);
                    break;
                }
                case 6:
                {
                    //system("cls");
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
    do {
        //system("cls");
        std::cout << "Авторизация в систему контроля рабочего персонала!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Авторизация в систему" << std::endl;
        std::cout << "2. Регистрация нового пользователя" << std::endl;
        std::cout << "3. Выход из системы" << std::endl;
        select = InputError::Input(1, 3);
        switch (select) {
            case 1: {
                User *currentUser = new User(Algorithm<User>::authorization());
                if (currentUser->getUsername() != "") {
                    return *currentUser;
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
    List<User> userList;
    File<User>::openUser(userList, "users.txt");
    std::vector<T> ReturnPrev;
    std::vector<int> action;
    std::vector<User> ReturnPrevForUsers;
    std::vector<int> actionOfUsers;
    std::vector<int> place;
    int select = 0;
    do {
        //system("cls");
        std::cout << "Вас приветствует система персонала компании!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Добавить сотрудника в систему" << std::endl;
        std::cout << "2. Посмотреть список сотрудников" << std::endl;
        std::cout << "3. Удалить последнего сотрудника из системы" << std::endl;
        std::cout << "4. Изменить данные о конкретном сотруднике" << std::endl;
        std::cout << "5. Отмена предыдущего действия с сотрудниками" << std::endl;
        std::cout << "6. Отсортировать список сотрудников" << std::endl;
        std::cout << "7. Добавить пользователя" << std::endl;
        std::cout << "8. Просмотреть список пользователей" << std::endl;
        std::cout << "9. Удалить пользователя" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        try {
            select = InputError::Input(0, 9);
            switch (select) {
                case 1:
                {
                    //system("cls");
                    Algorithm<T>::add(list, ReturnPrev, action);
                    break;
                }
                case 2:
                {
                    //system("cls");
                    if (list.size() == 0) {
                        throw ListException(1);
                    } else {
                        list.output();
                        std::cout << std::endl;
                        system("pause");
                    }
                    break;
                }
                case 3:
                {
                    //system("cls");
                    Algorithm<T>::remove(list, ReturnPrev, action);
                    break;
                }
                case 4:
                {
                    //system("cls");
                    Algorithm<T>::update(list, ReturnPrev, action, place);
                    break;
                }
                case 5:
                {
                    //system("cls");
                    Algorithm<T>::cancel(list, ReturnPrev, action, place);
                    break;
                }
                case 6:
                {
                    //system("cls");
                    Algorithm<T>::sort(list, ReturnPrev, action, place);
                    break;
                }
                case 7: {
                    //system("cls");
                    Algorithm<User>::add(userList, ReturnPrevForUsers, actionOfUsers);
                    break;
                }
                case 8: {
                    //system("cls");
                    if (userList.size() == 0) {
                        throw ListException(1);
                    } else {
                        userList.output();
                        std::cout << std::endl;
                        system("pause");
                    }
                    break;
                }
                case 9: {
                    //system("cls");
                    Algorithm<User>::remove(userList, ReturnPrevForUsers, actionOfUsers);
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


#endif //KURSACHKARPEICHIK_INTERFACE_H
