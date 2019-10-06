#ifndef SCHOLARSHIP_LIST_H
#define SCHOLARSHIP_LIST_H

#include <iostream>
#include <iomanip>

template <class T>
struct Node {
    T data;
    Node<T>* previous;
    Node<T>* next;
    int number;
};

template <class T>
class List {
protected:
    Node<T> *head;
    Node<T> *tail;
    int amount;
public:
    List() { head = nullptr; tail = nullptr; amount = 0; }
    ~List();

    //Длина списка
    int size() { return this->amount; }
    void pushHead(T obj);
    void pushTail(T input_object);
    T popHead();
    T popTail();
    T& operator[](int num);
    Node<T>* begin();
    Node<T>* end();
    void output();
    void sort(int type);
};

template<class T>
class Iterator {
    Node<T> *current;
public:
    Iterator() { current = nullptr; }

    Iterator(Iterator &iter) { current = iter.current; }
    ~Iterator() = default;
    // Получение узла из итератора
    Node<T>* getNode() { return current; }
    // Функции сдвига итератора
    bool operator++(int i) {
        if (current == nullptr) return false;
        current = current->next;
        return true;
    }
    bool operator--(int i) {
        if (current->prev == nullptr) return false;
        current = current->prev;
        return true;
    }
    // Получение значения из итератора
    T& operator*() {return current->data; }
    // Операторы сравнения для итератора
    bool operator==(Iterator &iter) {
        if (current == nullptr && iter.current == nullptr)
            return true;
        if (current == nullptr || iter.current == nullptr)
            return false;
        if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
            return true;
        return false;
    }

    bool operator!=(Iterator &iter) {
        if (current == nullptr && iter.current == nullptr)
            return false;
        if ((current == nullptr && iter.current != nullptr) || (current != nullptr && iter.current == nullptr))
            return true;
        if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
            return false;
        return true;
    }
};

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
        head->previous = nullptr;
        head->number = (amount++);
        tail = head;
        return;
    }
    auto *node = new Node<T>;
    node->data = input_object;
    node->next = nullptr;
    node->previous = tail;
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
        head->previous = nullptr;
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
        tail = tail->previous;
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
    setlocale(LC_ALL, "");
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    int i = 0;
    for (Node<T> *node = head; node != nullptr; node = node->next) {
        std::cout/* << std::left << std::setfill(' ')*/ << "|" << std::setw(3) << i + 1 << node->data;
        std::cout << std::endl;
        i++;
    }
}

template<class T>
List<T>::~List() { while (this->head) { this->popHead(); } }

template<class T>
void List<T>::sort(int type) {
    switch (type) {
        case 1: {
            for (Node<T> *tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
                for (Node<T> * another = this->tail; another != tmp; another = another->previous) {
                    if (tmp->data.getName() > another->data.getName()) {
                        auto *buf1 = new Node<T>;
                        buf1->data = tmp->data;
                        tmp->data = another->data;
                        another->data = buf1->data;
                    }
                }
            }
            break;
        }
        case 2: {
            for (Node<T> *tmp = this->head; tmp->next != this->tail; tmp = tmp->next) {
                for (Node<T> * another = this->tail; another != tmp; another = another->previous) {
                    if (tmp->data.getGroup() > another->data.getGroup()) {
                        auto *buf1 = new Node<T>;
                        buf1->data = tmp->data;
                        tmp->data = another->data;
                        another->data = buf1->data;
                    }
                }
            }
            break;
        }
        case 3: {
            for (Node<T> *tmp = this->head; tmp->next != this->tail; tmp = tmp->next) {
                for (Node<T> * another = this->tail; another != tmp; another = another->previous) {
                    if (tmp->data.getScholarship() > another->data.getScholarship()) {
                        auto *buf1 = new Node<T>;
                        buf1->data = tmp->data;
                        tmp->data = another->data;
                        another->data = buf1->data;
                    }
                }
            }
            break;
        }
    }
}


#endif //SCHOLARSHIP_LIST_H
