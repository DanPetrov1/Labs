#ifndef LAB3_THREEDSHAPE_H
#define LAB3_THREEDSHAPE_H

#include "Shape.h"

class ThreeDShape : public Shape {
protected:
    int length = 0, width = 0, height = 0;
public:
    ThreeDShape(int length, int width, int height) : length(length), width(width), height(height){};
    std::string type() override { return "3D-shape"; }
    virtual double volume() = 0;
    virtual double coverageArea() = 0;
    ~ThreeDShape() override { std::cout << "3D-shape's destructor" << std::endl; };
};


#endif //LAB3_THREEDSHAPE_H
