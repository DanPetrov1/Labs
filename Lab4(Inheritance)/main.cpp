#include <iostream>
#include "Headers/Person.h"
#include "Headers/Tourist.h"
#include "Headers/Businessman.h"
#include "Headers/Business.h"

int main() {
    Person person;
    std::cin >> person;
    std::cout << person;
    Tourist tourist;
    std::cin >> tourist;
    std::cout << tourist;
    Businessman businessman;
    std::cin >> businessman;
    std::cout << businessman;
    Business business;
    std::cin >> business;
    std::cout << business;
    return 0;
}