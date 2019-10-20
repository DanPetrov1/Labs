#ifndef LAB3_PARALLELEPIPED_H
#define LAB3_PARALLELEPIPED_H

#include "ThreeDShape.h"

class Parallelepiped : public ThreeDShape {
private:
    int width, height;
public:
    explicit Parallelepiped(int length, int width, int height) : width(width), height(height) , ThreeDShape(length) {};
    std::string type() final { return "Parallelepiped."; };
    double coverageArea() final { return 2 * (length * width + length * height + width * height);};
    double volume() final { return length * width * height; };
    ~Parallelepiped() final { std::cout << "Parallelepiped's destructor." << std::endl; };
};


#endif //LAB3_PARALLELEPIPED_H
