#include <iostream>
#include "../Headers/Shape.h"
#include "../Headers/Circle.h"
#include "../Headers/Rectangle.h"
#include "../Headers/Sphere.h"
#include "../Headers/Parallelepiped.h"

int main() {
    Shape* shape[] = {new Circle(3), new Rectangle(2, 3), new Sphere(5), new Parallelepiped(2, 3, 4)};
    Circle circle(3);
    std::cout << dynamic_cast<Shape&>(circle).type() << std::endl;
    std::cout << dynamic_cast<TwoDShape&>(circle).area() << std::endl;
    std::cout <<  shape[0]->type() << std::endl;
    std::cout << "Area: " << (dynamic_cast<Circle&>(*shape[0])).area() << std::endl;
    std::cout << "Perimeter: " << (dynamic_cast<Circle&>(*shape[0])).perimeter() << std::endl;
    delete shape[0];
    std::cout << shape[1]->type() << std::endl;
    std::cout << "Area: " << (dynamic_cast<Rectangle&>(*shape[1])).area() << std::endl;
    std::cout << "Perimeter:" << (dynamic_cast<Rectangle&>(*shape[1])).perimeter() << std::endl;
    delete shape[1];
    std::cout << shape[2]->type() << std::endl;
    std::cout << "Coverage area: " << (dynamic_cast<Sphere&>(*shape[2])).coverageArea() << std::endl;
    std::cout << "Volume: "<< (dynamic_cast<Sphere&>(*shape[2])).volume() << std::endl;
    delete shape[2];
    std::cout << shape[3]->type() << std::endl;
    std::cout << "Coverage area: " << (dynamic_cast<Parallelepiped&>(*shape[3])).coverageArea() << std::endl;
    std::cout << "Volume: "<< (dynamic_cast<Parallelepiped&>(*shape[3])).volume() << std::endl;
    delete shape[3];
    return 0;
}