#ifndef KURSACHKARPEICHIK_ALGORITHM_H
#define KURSACHKARPEICHIK_ALGORITHM_H

#define KEY 5

#include <iostream>
#include <vector>
#include <string>
#include "List.h"
#include "User.h"
#include "ListException.h"
#include "InputError.h"
#include "File.h"

template <class T>
class Algorithm {
public:
    static void registration();
    static User& authorization();
    static void add(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action);
    static void remove(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action);
    static void update(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place);
    static void sort(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place);
    static void cancel(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place);
};

template<class T>
void Algorithm<T>::add(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action) {
    //system("cls");
    T tmp;
    std::cin >> tmp;
    list.pushTail(tmp);
    returnPrev.insert(returnPrev.end(), tmp);
    action.insert(action.end(), 1);
    system("pause");
}

template<class T>
void Algorithm<T>::remove(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action) {
    //system("cls");
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
void Algorithm<T>::update(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place) {
    //system("cls");
    if (!list.size()) {
        throw ListException(1);
    }
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
void Algorithm<T>::sort(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place) {
    //system("cls");
    if (!list.size()) {
        throw ListException(1);
    }
    list.output();
    std::cout << std::endl;
    std::cout << "Выберите по какому признаку отсортировать:" << std::endl;
    std::cout << "1. По лицевому счёту по возрастанию." << std::endl;
    std::cout << "2. По лицевому счёту по убыванию." << std::endl;
    std::cout << "3. По зарплате по возрастанию." << std::endl;
    std::cout << "4. По зарплате по убыванию." << std::endl;
    int type = InputError::Input(1, 4);
    list.sort(type);
}

template<class T>
void Algorithm<T>::cancel(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place) {
    if (!action.size()) {
        //system("cls");
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
User& Algorithm<T>::authorization() {
    List<User> users;
    File<User>::openUser(users, "users.txt");
    char BUFFER[20];
    std::string username;
    std::cout << "Введите логин: ";
    std::cin >> username;
    std::cout << "Введите пароль: ";
    std::cin >> BUFFER;
    for (int j = 0; BUFFER[j] != '\0'; ++j) {
        BUFFER[j] = BUFFER[j] + j * KEY;
    }
    std::string password(BUFFER);
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == username && users[i].getPassword() == password) {
            return users[i];
        }
    }
    std::cout << "Неверный пользователь или пароль!" << std::endl;
    return *(new User("", "", false));
}

template<class T>
void Algorithm<T>::registration() {
    List<User> users;
    File<User>::openUser(users, "users.txt");
    User newUser;
    std::cin >> newUser;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == newUser.getUsername() && users[i].getPassword() == newUser.getPassword()
                    && newUser.isAdmin() != users[i].isAdmin()) {
            std::cout << "Данный пользователь уже существует!" << std::endl;
            return;
        }
    }
    users.pushTail(newUser);
    File<User>::saveUser(users, "users.txt");
}


#endif //KURSACHKARPEICHIK_ALGORITHM_H
