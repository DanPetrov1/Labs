#include <iostream>
#include "String.h"

int main() {
    int command;

    while (true)
    {
        std::cout << "Choose the variant:" << std::endl
                  << "1. =" << std::endl
                  << "2. +" << std::endl
                  << "3. +=" << std::endl
                  << "4. ==" << std::endl
                  << "5. !=" << std::endl
                  << "6. >" << std::endl
                  << "7. >=" << std::endl
                  << "8. <" << std::endl
                  << "9. <=" << std::endl
                  << "10. ++" << std::endl
                  << "11. --" << std::endl
                  << "12. [] and ()" << std::endl
                  << "13. Substring" << std::endl
                  << "14. Exit." << std::endl;

        std::cin >> command;
        switch (command) {
            case 1: {
                String firstString;
                String secondString;

                std::cout << "Write the first string:" << std::endl;
                std::cin.get();
                std::cin >> firstString;
                std::cout << "Write the second string:" << std::endl;
                std::cin >> secondString;

                std::cout << "First string:" << std::endl;
                std::cout << firstString;
                std::cout << "Second string:" << std::endl;
                std::cout << secondString;

                firstString = secondString;
                std::cout << "Result: " << firstString;
                break;
            }
            case 2: {
                String firstString;
                String secondString;

                std::cout << "Write the first string:" << std::endl;
                std::cin.get();
                std::cin >> firstString;
                std::cout << "Write the second string:" << std::endl;
                std::cin >> secondString;

                std::cout << "First string:" << std::endl;
                std::cout << firstString;
                std::cout << "Second string:" << std::endl;
                std::cout << secondString;

                std::cout << "Result: " << (firstString + secondString);
                break;
            }
            case 3: {
                String firstString;
                String secondString;

                std::cout << "Write the first string:" << std::endl;
                std::cin.get();
                std::cin >> firstString;
                std::cout << "Write the second string:" << std::endl;
                std::cin >> secondString;

                std::cout << "First string:" << std::endl;
                std::cout << firstString;
                std::cout << "Second string:" << std::endl;
                std::cout << secondString;

                firstString += secondString;
                std::cout << "Result: " << firstString;
                break;
            }
            case 4: {
                String firstString;
                String secondString;

                std::cout << "Write the first string:" << std::endl;
                std::cin.get();
                std::cin >> firstString;
                std::cout << "Write the second string:" << std::endl;
                std::cin >> secondString;

                std::cout << "First string:" << std::endl;
                std::cout << firstString;
                std::cout << "Second string:" << std::endl;
                std::cout << secondString;

                std::cout << "Result: " << (firstString == secondString) << std::endl;
                break;
            }
            case 5: {
                String firstString;
                String secondString;

                std::cout << "Write the first string:" << std::endl;
                std::cin.get();
                std::cin >> firstString;
                std::cout << "Write the second string:" << std::endl;
                std::cin >> secondString;

                std::cout << "First string:" << std::endl;
                std::cout << firstString;
                std::cout << "Second string:" << std::endl;
                std::cout << secondString;

                std::cout << "Result: " << (firstString != secondString) << std::endl;
                break;
            }
            case 6: {
                String firstString;
                String secondString;

                std::cout << "Write the first string:" << std::endl;
                std::cin.get();
                std::cin >> firstString;
                std::cout << "Write the second string:" << std::endl;
                std::cin >> secondString;

                std::cout << "First string:" << std::endl;
                std::cout << firstString;
                std::cout << "Second string:" << std::endl;
                std::cout << secondString;

                std::cout << "Result: " << (firstString > secondString) << std::endl;
                break;
            }
            case 7: {
                String firstString;
                String secondString;

                std::cout << "Write the first string:" << std::endl;
                std::cin.get();
                std::cin >> firstString;
                std::cout << "Write the second string:" << std::endl;
                std::cin >> secondString;

                std::cout << "First string:" << std::endl;
                std::cout << firstString;
                std::cout << "Second string:" << std::endl;
                std::cout << secondString;

                std::cout << "Result: " << (firstString >= secondString) << std::endl;
                break;
            }
            case 8: {
                String firstString;
                String secondString;

                std::cout << "Write the first string:" << std::endl;
                std::cin.get();
                std::cin >> firstString;
                std::cout << "Write the second string:" << std::endl;
                std::cin >> secondString;

                std::cout << "First string:" << std::endl;
                std::cout << firstString;
                std::cout << "Second string:" << std::endl;
                std::cout << secondString;

                std::cout << "Result: " << (firstString < secondString) << std::endl;
                break;
            }
            case 9: {
                String firstString;
                String secondString;

                std::cout << "Write the first string:" << std::endl;
                std::cin.get();
                std::cin >> firstString;
                std::cout << "Write the second string:" << std::endl;
                std::cin >> secondString;

                std::cout << "First string:" << std::endl;
                std::cout << firstString;
                std::cout << "Second string:" << std::endl;
                std::cout << secondString;

                std::cout << "Result: " << (firstString <= secondString) << std::endl;
                break;
            }
            case 10: {
                String my_str;

                std::cout << "Write the string:" << std::endl;
                std::cin.get();
                std::cin >> my_str;

                std::cout << "String: " << my_str;
                std::cout << "Result: " << (++my_str);
                break;
            }
            case 11: {
                String my_str;

                std::cout << "Write the string:" << std::endl;
                std::cin.get();
                std::cin >> my_str;

                std::cout << "String: " << my_str;
                std::cout << "Result: " << --my_str;
                break;
            }
            case 12: {
                String my_str;
                int index;

                std::cout << "Write the string:" << std::endl;
                std::cin.get();
                std::cin >> my_str;
                std::cout << "Write the index:" << std::endl;
                std::cin >> index;

                std::cout << "String: " << my_str;
                std::cout << "Result: " << my_str[index] << " " << my_str(index) << std::endl;
                break;
            }
            case 13: {
                String my_str;
                int begin, end;

                std::cout << "Write the string:" << std::endl;
                std::cin.get();
                std::cin >> my_str;
                std::cout << "Write the begin:" << std::endl;
                std::cin >> begin;
                std::cout << "Write the end:" << std::endl;
                std::cin >> end;

                std::cout << "String: " << my_str;
                String result = my_str(begin, end);
                std::cout << "Result: " << result << std::endl;
                break;
            }
            case 14:
                return 0;
            default:
                std::cout << "Invalid input. Please, try again." << std::endl;
        }
    }
}