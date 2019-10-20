#ifndef LAB3_THREEDSHAPE_H
#define LAB3_THREEDSHAPE_H

#include "Shape.h"

class ThreeDShape : public Shape {
protected:
    int length = 0;
public:
    explicit ThreeDShape(int length) : length(length){};
    std::string type() override { return "3D-shape"; }
    virtual double volume() = 0;
    virtual double coverageArea() = 0;
    ~ThreeDShape() override { std::cout << "3D-shape's destructor" << std::endl; };
};


#endif //LAB3_THREEDSHAPE_H
