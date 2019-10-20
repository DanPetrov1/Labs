#ifndef LAB3_TWODSHAPE_H
#define LAB3_TWODSHAPE_H

#include "Shape.h"

class TwoDShape : public Shape {
protected:
    int length = 0;
public:
    TwoDShape(int length) : length(length) {};
    std::string type() override { return "2D-shape"; }
    virtual double area() = 0;
    virtual double perimeter() = 0;
    ~TwoDShape() override { std::cout << "2D-shape's destructor" << std::endl; };
};


#endif //LAB3_TWODSHAPE_H
