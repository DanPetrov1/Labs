#ifndef LAB3_CIRCLE_H
#define LAB3_CIRCLE_H

#include <cmath>
#include "TwoDShape.h"

class Circle : public TwoDShape {
public:
    explicit Circle(int radius) : TwoDShape(radius){};
    std::string type() final { return "Circle."; };
    double area() final { return 3.14 * pow(length, 2); };
    double perimeter() final { return 2 * 3.14 * length; };
    ~Circle() final { std::cout << "Circle's destructor." << std::endl; };
};


#endif //LAB3_CIRCLE_H
