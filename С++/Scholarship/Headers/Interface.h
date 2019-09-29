#ifndef SCHOLARSHIP_INTERFACE_H
#define SCHOLARSHIP_INTERFACE_H

#include "../Headers/Student.h"
#include "../Headers/UndergraduateStudent.h"
#include "../Headers/GraduateStudent.h"
#include "../Headers/File.h"
#include "../Headers/List.h"
#include "../Headers/InputError.h"
#include "../Headers/MyException.h"
#include <vector>
#include <iomanip>

template<class T>
class Interface {
public:
    static void menu(List<T>& list);
    static void add(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action);
    static void remove(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action);
    static void update(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place);
    static void sort(List<T> &list, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place);
    static void cancel(List<T>& list, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place);
    static void line(int size)
    {
        std::cout << std::setfill('-') << std::setw(size) << "" << std::endl;
        std::cout << std::setfill(' ');
    }
};


#endif //SCHOLARSHIP_INTERFACE_H
