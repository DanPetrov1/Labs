#ifndef LAB3_SPHERE_H
#define LAB3_SPHERE_H

#include <cmath>
#include "ThreeDShape.h"

class Sphere : public ThreeDShape {
public:
    explicit Sphere(int radius) : ThreeDShape(radius){};
    std::string type() final { return "Sphere."; };
    double coverageArea() final { return 4 * 3.14 * pow(length, 2);};
    double volume() final { return (4 / 3 * 3.14 * pow(length, 3)); };
    ~Sphere() final { std::cout << "Sphere's destructor." << std::endl; };
};

#endif //LAB3_SPHERE_H
