#include <iostream>
#include <string>
#include "Array.hpp"

const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main()
{
    std::cout << BOLD << UNDERLINE << "\nTesting with integers :" << RESET << std::endl;
    std::cout << "\nTesting default constructor:" << std::endl;
    Array<int> emptyArr;
    std::cout << "Size of empty array: " << emptyArr.size() << std::endl;
    std::cout << "\nTesting exception on out-of-bounds access:" << std::endl;
    Array<int> intArr(5);
    try {
        intArr[intArr.size()] = 42;
        std::cout << "Exception not thrown!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught : out of bounds index" << std::endl;
    }
    std::cout << "\nTesting element modification:" << std::endl;
    for (unsigned int i = 0; i < intArr.size(); ++i)
        intArr[i] = i * 10;
    
    std::cout << "Elements after modification:" << std::endl;
    for (unsigned int i = 0; i < intArr.size(); ++i)
        std::cout << "intArr[" << i << "] = " << intArr[i] << std::endl;

    std::cout << "\nTesting copy constructor:" << std::endl;
    Array<int> copiedArr(intArr);
    std::cout << "Size of copied array: " << copiedArr.size() << std::endl;
    std::cout << "Elements in copied array:" << std::endl;
    for (unsigned int i = 0; i < copiedArr.size(); ++i)
        std::cout << "copiedArr[" << i << "] = " << copiedArr[i] << std::endl;
    
    std::cout << BOLD << UNDERLINE << "\nTesting with strings :" << RESET << std::endl;

    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "World";
    strArr[2] = "!";
    
    std::cout << "String array contents:" << std::endl;
    for (unsigned int i = 0; i < strArr.size(); ++i)
        std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;

    Array<std::string> strArrCopy = strArr;
    strArr[0] = "Modified";
    
    std::cout << "\nAfter modifying original:" << std::endl;
    std::cout << "Original: " << strArr[0] << std::endl;
    std::cout << "Copy: " << strArrCopy[0] << std::endl;
    
    std::cout << BOLD << UNDERLINE << "\nTesting edge case :" << RESET << std::endl;

    Array<double> zeroArr(0);
    std::cout << "Size of zero array: " << zeroArr.size() << std::endl;

    try {
        std::cout << "Accessing element in empty array: ";
        double value = zeroArr[0];
        std::cout << value << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught" << std::endl;
    }

    return 0;
}