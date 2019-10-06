#ifndef LAB3_SPHERE_H
#define LAB3_SPHERE_H

#include <cmath>
#include "ThreeDShape.h"

class Sphere : public ThreeDShape {
private:
    int radius = 0;
public:
    explicit Sphere(int radius) : radius(radius), ThreeDShape(radius, radius, radius){};
    std::string type() final { return "Sphere."; };
    double coverageArea() final { return 4 * 3.14 * pow(radius, 2);};
    double volume() final { return (4 / 3 * 3.14 * pow(radius, 3)); };
    ~Sphere() final { std::cout << "Sphere's destructor." << std::endl; };
};


#endif //LAB3_SPHERE_H
