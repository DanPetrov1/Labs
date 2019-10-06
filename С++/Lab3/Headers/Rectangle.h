#ifndef LAB3_RECTANGLE_H
#define LAB3_RECTANGLE_H

#include "TwoDShape.h"

class Rectangle : public TwoDShape {
public:
    explicit Rectangle(int length, int width) : TwoDShape(length, width) {};
    std::string type() final { return "Rectangle."; };
    double area() final { return length * width; };
    double perimeter() final { return 2 * (width + length); };
    ~Rectangle() final { std::cout << "Rectangle's destructor." << std::endl; };
};


#endif //LAB3_RECTANGLE_H
