#ifndef KURSACHKARPEICHIK_FILE_H
#define KURSACHKARPEICHIK_FILE_H

#include "List.h"

template <class T>
class File {
public:
    File() = default;
    ~File() = default;;

    static void openUser(List<T>& list, const char *file);
    static void openSpecialist(List<T>& list, const char *file);
    static void openSupervisor(List<T>& list, const char *file);
    static void openTrainee(List<T>& list, const char *file);

    static void saveUser(List<T>& list, const char *file);
    static void saveSpecialist(List<T>& list, const char *file);
    static void saveSupervisor(List<T>& list, const char *file);
    static void saveTrainee(List<T>& list, const char *file);
};

template<class T>
void File<T>::openUser(List<T> &list, const char *file) {

}

template<class T>
void File<T>::openSpecialist(List<T> &list, const char *file) {

}

template<class T>
void File<T>::openSupervisor(List<T> &list, const char *file) {

}

template<class T>
void File<T>::openTrainee(List<T> &list, const char *file) {

}

template<class T>
void File<T>::saveUser(List<T> &list, const char *file) {

}

template<class T>
void File<T>::saveSpecialist(List<T> &list, const char *file) {

}

template<class T>
void File<T>::saveSupervisor(List<T> &list, const char *file) {

}

template<class T>
void File<T>::saveTrainee(List<T> &list, const char *file) {

}


#endif //KURSACHKARPEICHIK_FILE_H
