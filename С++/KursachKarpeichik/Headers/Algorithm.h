#ifndef KURSACHKARPEICHIK_ALGORITHM_H
#define KURSACHKARPEICHIK_ALGORITHM_H

#include <iostream>
#include <vector>
#include "List.h"
#include "User.h"

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
    system("cls");
    T tmp;
    std::cin >> tmp;
    list.pushTail(tmp);
    returnPrev.insert(returnPrev.end(), tmp);
    action.insert(action.end(), 1);
    system("pause");
}

template<class T>
void Algorithm<T>::remove(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action) {
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
void Algorithm<T>::update(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place) {
    system("cls");
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
    system("cls");
    if (!list.size()) {
        throw ListException(1);
    }
    list.output();
    std::cout << std::endl;
    std::cout << "Выберите по какому признаку отсортировать: ";
    int tempNum = InputError::Input(1, list.size());

}

template<class T>
void Algorithm<T>::cancel(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place) {
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
User &Algorithm<T>::authorization() {
    List<User> users;
    File<User>::openUser(users, "users.txt");
    char username[20], password[20];
    std::cout << "";
    std::cin >> username;
    std::cout << "";
    std::cin >> password;
    for (int i = 0; i < users.size(); i++) {
        if (!strcmp(users[i].getUsername(), username) && !strcmp(users[i].getPassword(), password)) {
            return users[i];
        }
    }
    std::cout << "Неверный пользователь или пароль!" << std::endl;
    return User("", "", false);
}

template<class T>
void Algorithm<T>::registration() {
    List<User> users;
    File<User>::openUser(users, "users.txt");
    User newUser;
    std::cin >> newUser;
    for (int i = 0; i < users.size(); i++) {
        if (!strcmp(users.operator[](i).getUsername(), newUser.getUsername()) && !strcmp(users.operator[](i).getPassword(), newUser.getPassword())
                    && newUser.isAdmin() != users.operator[](i).isAdmin()) {
            std::cout << "Данный пользователь уже существует!" << std::endl;
            return;
        }
    }
    users.pushTail(newUser);
    File<User>::saveUser(users, "users.txt");
    return;
}


#endif //KURSACHKARPEICHIK_ALGORITHM_H
