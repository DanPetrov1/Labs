#include "../Headers/List.h"
#include <iostream>
#include <iomanip>

//Добавление с головы
template<class T>
void List<T>::pushHead(T obj) {
    if (head == nullptr) {
        head = new Node<T>;
        head->data = obj;
        head->next = nullptr;
        head->prev = nullptr;
        head->number = (amount++);
        tail = head;
    } else {
        auto *node = new Node<T>;
        node->data = obj;
        node->next = head;
        node->prev = nullptr;
        head->prev = node;
        head = node;
        for (int i = 0;node;node = node->next, i++) {
            node->number = i;
        }
        amount++;
    }
}

//Добавление в хвост
template<class T>
void List<T>::pushTail(T input_object) {
    if (head == nullptr) {
        head = new Node<T>;
        head->data = input_object;
        head->next = nullptr;
        head->prev = nullptr;
        head->number = (amount++);
        tail = head;
        return;
    }
    auto *node = new Node<T>;
    node->data = input_object;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;
    node->number = (amount++);
}

//Удаление от головы
template<class T>
T List<T>::popHead() {
    if (!(head)) return T();
    T data = head->data;
    Node<T>* node = head;
    if (head != tail) {
        head = head->next;
        head->prev = nullptr;
        Node<T>* tmp = head;
        for (int i = 0;tmp;tmp = tmp->next, i++) {
            tmp->number = i;
        }
    } else {
        head = tail = nullptr;
    }
    delete node;
    amount--;
    return data;
}

//Удаление из хвоста
template<class T>
T List<T>::popTail() {
    if (!(head)) return T();
    T data = tail->data;
    Node<T> *node = tail;
    if (tail != head) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        head = tail = nullptr;
    }
    delete node;
    amount--;
    return data;
}

// Доступ к объектам с помощью индексации
template<class T>
T& List<T>::operator[](int num) {
    Node<T> *curr = head;
    if (num < 0 || num >= amount) return curr->data;
    for (int i = 0; i < num; i++)
        curr = curr->next;
    return curr->data;
}

// Функции для работы с итератором
template<class T>
Node<T>* List<T>::begin() { return head; }

template<class T>
Node<T>* List<T>::end() {
    if (tail != nullptr) return tail->next;
    return tail;
}

// Вывод на экран содержимого списка
template<class T>
void List<T>::output() {
    int i = 0;
    for (Node<T> *node = head; node != nullptr; node = node->next) {
        std::cout << "|" << std::setw(3) << i + 1 << node->data;
        std::cout << std::endl;
        i++;
    }
}