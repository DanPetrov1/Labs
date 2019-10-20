#ifndef LAB3_SHAPE_H
#define LAB3_SHAPE_H

#include <string>
#include <iostream>

class Shape {
public:
    virtual ~Shape() { std::cout << "Shape's destructor." << std::endl; };
    virtual std::string type() = 0;
};

#endif //LAB3_SHAPE_H
