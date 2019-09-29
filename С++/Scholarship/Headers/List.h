#ifndef SCHOLARSHIP_LIST_H
#define SCHOLARSHIP_LIST_H

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
    friend class MyIterator;
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


    class MyIterator {
        Node<T> *current;
    public:
        MyIterator() { current = nullptr; }
        MyIterator(List<T> &container) { current = container.head; }
        MyIterator(MyIterator &iter) { current = iter.current; }
        MyIterator(Node<T> *node) { current = node; }
        ~MyIterator() = default;
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
        bool operator==(MyIterator &iter) {
            if (current == nullptr && iter.current == nullptr)
                return true;
            if (current == nullptr || iter.current == nullptr)
                return false;
            if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
                return true;
            return false;
        }

        bool operator!=(MyIterator &iter) {
            if (current == nullptr && iter.current == nullptr)
                return false;
            if ((current == nullptr && iter.current != nullptr) || (current != nullptr && iter.current == nullptr))
                return true;
            if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
                return false;
            return true;
        }
    };
};

#endif //SCHOLARSHIP_LIST_H
