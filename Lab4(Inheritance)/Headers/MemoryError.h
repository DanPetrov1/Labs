//
// Created by dan on 28.10.19.
//

#ifndef LAB4_INHERITANCE__MEMORYERROR_H
#define LAB4_INHERITANCE__MEMORYERROR_H

#include <iostream>
#include "MyException.h"

template <class T>
class MemoryError : public MyException {
public:
    explicit MemoryError(int code = 0) : MyException(code) {};
    void errorText() override;
    T*getMemory(T*data, int size);
    T getElement(T*data, int index);
    T*reallocateMemory(T*data, int newSize);
};

template<class T>
T *MemoryError<T>::getMemory(T *data, int size) {
    try {
        if (size <= 0) {
            throw (MemoryError(3));
        }
        data = new T[size];
        if (!data) {
            throw (MemoryError(0));
        }
    }
    catch (MemoryError e) {
        e.errorText();
    }
    return data;
}

template<class T>
void MemoryError<T>::errorText() {
    std::cout << "Ошибка ввода (код " << this->code << "): ";
    switch (code) {
        case 0:
            std::cout << "Ошибка выделения памяти!" << std::endl;
            break;
        case 1:
            std::cout << "Данного элемента не существует!" << std::endl;
            break;
        case 2:
            std::cout << "Ошибка перевыделения памяти!" << std::endl;
            break;
        case 3:
            std::cout << "Нельзя выделить отрицательный или нулевой размер памяти!" << std::endl;
            break;
    }
}

template<class T>
T MemoryError<T>::getElement(T*data, int index) {
    try {
        if (!data || !data[index]) {
            throw (MemoryError(1));
        }
        return data[index];
    }
    catch (MemoryError e) {
        e.errorText();
        return nullptr;
    }
}

template<class T>
T *MemoryError<T>::reallocateMemory(T *data, int newSize) {
    try {
        data = realloc(data, newSize * sizeof(T));
        if (!data) {
            throw (MemoryError(2));
        }
    }
    catch (MemoryError e) {
        e.errorText();
        return nullptr;
    }
    return data;
}


#endif //LAB4_INHERITANCE__MEMORYERROR_H
