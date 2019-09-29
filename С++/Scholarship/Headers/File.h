#ifndef SCHOLARSHIP_FILE_H
#define SCHOLARSHIP_FILE_H

#include "List.h"

template <class T>
class File {
public:
    File() = default;
    ~File() = default;;

    void openStudent(List<T>& list, const char *file);
    void openUndergraduate(List<T>& list, const char *file);
    void openGraduate(List<T>& list, const char *file);

    void saveStudent(List<T>& list, const char *file);
    void saveUndergraduate(List<T>& list, const char *file);
    void saveGraduate(List<T>& list, const char *file);
};


#endif //SCHOLARSHIP_FILE_H
