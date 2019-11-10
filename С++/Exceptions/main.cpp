#include <iostream>
#include "Windows.h"
#include "Headers/Business.h"
#include "Headers/InputError.h"
#include "Headers/MemoryError.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int variant = 0, updateVariant, size = 2;
    Business* business = nullptr;
    business = MemoryError<Business>::getMemory(business, 2);
    for (int i = 0; i < size; ++i) {
        std::cin >> business[i];
    }
    business[0].table();
    for (int j = 0; j < size; ++j) {
        std::cout << (MemoryError<Business>::getElement(business, j));
    }
    while (variant != 4) {
        std::cout << "Choose variant:\n1. Add.\n2. Update.\n3. Show.\n4. Exit.\n";
        variant = InputError::input(1, 4);
        switch (variant) {
            case 1: {
                business = MemoryError<Business>::reallocateMemory(business, ++size);
                std::cin >> business[size - 1];
                break;
            }
            case 2: {
                int elementNumber, bufferNumber;
                char* buffer;
                std::cout << "Choose the number of the element to update: ";
                elementNumber = InputError::input(1, size);
                std::cout << "Choose the element to update:\n1. Surname.\n2. Name.\n3. Birthday year.\n4. Passport number.\n5. License number.\n";
                updateVariant = InputError::input(1, 5);
                switch (updateVariant) {
                    case 1: {
                        std::cout << "Old surname - " << business[elementNumber - 1].getSurname() << std::endl;
                        std::cout << "Write new surname: ";
                        rewind(stdin);
                        buffer = InputError::inputString();
                        business[elementNumber - 1].setSurname(buffer);
                        break;
                    }
                    case 2: {
                        std::cout << "Old name - " << business[elementNumber - 1].getName() << std::endl;
                        std::cout << "Write new name: ";
                        rewind(stdin);
                        buffer = InputError::inputString();
                        business[elementNumber - 1].setName(buffer);
                        break;
                    }
                    case 3: {
                        std::cout << "Old birthday year - " << business[elementNumber - 1].getBirthdayYear() << std::endl;
                        std::cout << "Write new birthday year: ";
                        bufferNumber = InputError::input(1, 2019);
                        business[elementNumber - 1].setBirthdayYear(bufferNumber);
                        break;
                    }
                    case 4: {
                        std::cout << "Old passport number - " << business[elementNumber - 1].getPassportNumber() << std::endl;
                        std::cout << "Write new passport number: ";
                        bufferNumber = InputError::input(100000, 999999);
                        business[elementNumber - 1].setPassportNumber(bufferNumber);
                        break;
                    }
                    case 5: {
                        std::cout << "Old license number - " << business[elementNumber - 1].getLicenceNumber() << std::endl;
                        std::cout << "Write new license number: ";
                        bufferNumber = InputError::input(100000, 999999);
                        business[elementNumber - 1].setLicenceNumber(bufferNumber);
                        break;
                    }
                }
                break;
            }
            case 3: {
                business[0].table();
                for (int i = 0; i < size; ++i) {
                    std::cout << (MemoryError<Business>::getElement(business, i));
                }
            }
        }
    }
    delete[] business;
    return 0;
}