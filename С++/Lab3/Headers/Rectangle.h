#ifndef LAB3_RECTANGLE_H
#define LAB3_RECTANGLE_H

#include "TwoDShape.h"

class Rectangle : public TwoDShape {
private:
    int width;
public:
    explicit Rectangle(int length, int width) : width(width), TwoDShape(length) {};
    std::string type() final { return "Rectangle."; };
    double area() final { return length * width; };
    double perimeter() final { return 2 * (width + length); };
    ~Rectangle() final { std::cout << "Rectangle's destructor." << std::endl; };
};


#endif //LAB3_RECTANGLE_H
