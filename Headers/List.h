#ifndef KURSACHKARPEICHIK_LIST_H
#define KURSACHKARPEICHIK_LIST_H


template <class T>
struct Node {
    T data;
    Node<T>* previous;
    Node<T>* next;
};

template <class T>
class List {
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int amount = 0;
public:
    List() {};
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
};

template<class T>
void List<T>::pushHead(T obj) {
    if (head == nullptr) {
        head = new Node<T>;
        head->data = obj;
        head->next = nullptr;
        head->previous = nullptr;
        tail = head;
    } else {
        auto *node = new Node<T>;
        node->data = obj;
        node->next = head;
        node->previous = nullptr;
        head->previous = node;
        head = node;
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
        tail = head;
        return;
    }
    auto *node = new Node<T>;
    node->data = input_object;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;
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
    int i = 0;
    for (Node<T> *node = head; node != nullptr; node = node->next) {
        std::cout << "|№" << i + 1 << std::endl << node->data;
        std::cout << std::endl;
        i++;
    }
}

template<class T>
List<T>::~List() { while (this->head) { this->popHead(); } }

#endif //KURSACHKARPEICHIK_LIST_H
