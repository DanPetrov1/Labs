//
// Created by danpe on 08.11.2019.
//

#ifndef EXCEPTIONS_MEMORYERROR_H
#define EXCEPTIONS_MEMORYERROR_H

#include <iostream>
#include "MyException.h"

template <class T>
class MemoryError : public MyException {
public:
    explicit MemoryError(int code = 0) : MyException(code) {};
    void errorText() override;
    static T*getMemory(T*data, int size);
    static T& getElement(T*data, int index);
    static T*reallocateMemory(T*data, int newSize);
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
T& MemoryError<T>::getElement(T*data, int index) {
    try {
        if (index >= _msize(data) / sizeof(T)) {
            throw (MemoryError(1));
        }
        return data[index];
    }
    catch (MemoryError e) {
        e.errorText();
    }
}

template<class T>
T *MemoryError<T>::reallocateMemory(T *data, int newSize) {
    try {
        T* newData = new T[newSize];
        if (!newData) {
            throw (MemoryError(2));
        }
        for (int i = 0; i < newSize - 1; i++) {
            newData[i] = data[i];
        }
        return newData;
    }
    catch (MemoryError e) {
        e.errorText();
        return nullptr;
    }
}

#endif //EXCEPTIONS_MEMORYERROR_H
