#include <iostream>
#include "../Headers/Shape.h"
#include "../Headers/Circle.h"
#include "../Headers/Rectangle.h"
#include "../Headers/Sphere.h"
#include "../Headers/Parallelepiped.h"

int main() {
    Shape *shape[] = {new Shape(), new Circle(3), new Rectangle(2, 3), new Sphere(5), new Parallelepiped(2, 3, 4)};
    std::cout << shape[0]->type() << std::endl;
    delete shape[0];
    std::cout <<  shape[1]->type() << std::endl;
    std::cout << "Area: " << (dynamic_cast<Circle&>(*shape[1])).area() << std::endl;
    std::cout << "Perimeter: " << (dynamic_cast<Circle&>(*shape[1])).perimeter() << std::endl;
    delete shape[1];
    std::cout << shape[2]->type() << std::endl;
    std::cout << "Area: " << (dynamic_cast<Rectangle&>(*shape[2])).area() << std::endl;
    std::cout << "Perimeter:" << (dynamic_cast<Rectangle&>(*shape[2])).perimeter() << std::endl;
    delete shape[2];
    std::cout << shape[3]->type() << std::endl;
    std::cout << "Coverage area: " << (dynamic_cast<Sphere&>(*shape[3])).coverageArea() << std::endl;
    std::cout << "Volume: "<< (dynamic_cast<Sphere&>(*shape[3])).volume() << std::endl;
    delete shape[3];
    std::cout << shape[4]->type() << std::endl;
    std::cout << "Coverage area: " << (dynamic_cast<Parallelepiped&>(*shape[4])).coverageArea() << std::endl;
    std::cout << "Volume: "<< (dynamic_cast<Parallelepiped&>(*shape[4])).volume() << std::endl;
    delete shape[4];
    return 0;
}