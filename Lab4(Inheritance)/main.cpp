#include <iostream>
#include "Headers/Person.h"
#include "Headers/Tourist.h"
#include "Headers/Businessman.h"
#include "Headers/Business.h"

int main() {
    /*Person person;
    std::cin >> person;
    std::cout << person;
    Tourist tourist;
    std::cin >> tourist;
    std::cout << tourist;
    Businessman businessman;
    std::cin >> businessman;
    std::cout << businessman;*/
    Business* business = new Business[2];
    for (int i = 0; i < 2; ++i) {
        std::cin >> business[i];
    }
    business->table();
    for (int j = 0; j < 2; ++j) {
        std::cout << business[j];
    }
    return 0;
}