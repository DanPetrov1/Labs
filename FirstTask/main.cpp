#include <iostream>
#include "Matrix.h"

int main() {
    int size;
    int command;

    while (true)
    {
        std::cout << "Choose the variant:" << std::endl
                  << "1. Sum matrix." << std::endl
                  << "2. Multiply matrix." << std::endl
                  << "3. Subtract matrix." << std::endl
                  << "4. Add 1 to matrix." << std::endl
                  << "5. Subtract 1 from matrix." << std::endl
                  << "6. Exit." << std::endl;

        std::cin >> command;
        switch (command) {
            case 1: {
                std::cout << "Enter the size of the matrix: " << std::endl;
                std::cin >> size;
                Matrix firstMatrix(size);
                Matrix secondMatrix(size);

                std::cout << "Enter 1st matrix: " << std::endl;
                std::cin >> firstMatrix;
                std::cout << "Enter 2nd matrix: " << std::endl;
                std::cin >> secondMatrix;

                std::cout << "1-st matrix: ";
                std::cout << firstMatrix;
                std::cout << "2-nd matrix: ";
                std::cout << secondMatrix;

                Matrix resultMatrix = firstMatrix + secondMatrix;
                std::cout << "Result";
                std::cout << resultMatrix;
                break;
            }
            case 2: {
                std::cout << "Enter the size of the matrix: " << std::endl;
                std::cin >> size;
                Matrix firstMatrix(size);
                Matrix secondMatrix(size);

                std::cout << "Enter 1st matrix: " << std::endl;
                std::cin >> firstMatrix;
                std::cout << "Enter 2nd matrix: " << std::endl;
                std::cin >> secondMatrix;

                std::cout << "1-st matrix: ";
                std::cout << firstMatrix;
                std::cout << "2-nd matrix: ";
                std::cout << secondMatrix;

                Matrix resultMatrix = firstMatrix * secondMatrix;
                std::cout << "Result";
                std::cout << resultMatrix;
                break;
            }
            case 3: {
                std::cout << "Enter the size of the matrix: " << std::endl;
                std::cin >> size;
                Matrix firstMatrix(size);
                Matrix secondMatrix(size);

                std::cout << "Enter 1st matrix: " << std::endl;
                std::cin >> firstMatrix;
                std::cout << "Enter 2nd matrix: " << std::endl;
                std::cin >> secondMatrix;

                std::cout << "1-st matrix: ";
                std::cout << firstMatrix;
                std::cout << "2-nd matrix: ";
                std::cout << secondMatrix;

                Matrix resultMatrix = firstMatrix - secondMatrix;
                std::cout << "Result";
                std::cout << resultMatrix;
                break;
            }
            case 4: {
                std::cout << "Enter the size of the matrix: " << std::endl;
                std::cin >> size;
                Matrix matrix(size);

                std::cout << "Enter the matrix: " << std::endl;
                std::cin >> matrix;

                std::cout << "Matrix: ";
                std::cout << matrix;

                ++matrix;
                std::cout << "Result";
                std::cout << matrix;
                break;
            }
            case 5: {
                std::cout << "Enter the size of the matrix: " << std::endl;
                std::cin >> size;
                Matrix matrix(size);

                std::cout << "Enter the matrix: " << std::endl;
                std::cin >> matrix;

                std::cout << "Matrix: ";
                std::cout << matrix;

                --matrix;
                std::cout << "Result";
                std::cout << matrix;
                break;
            }
            case 6:
                return 0;
            default:
                std::cout << "Invalid input. Please, try again." << std::endl;
        }
    }
}