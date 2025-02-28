#include "iter.hpp"

const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main() {
    std::cout << BOLD << UNDERLINE << "\nTest int array" << RESET << std::endl;

    int intArr[] = {12, 35, 4, 1};
    std::cout << UNDERLINE << "\nbefore iter :" << RESET << std::endl;
    iter(intArr, 4, print<int>);
    std::cout << std::endl;

    iter(intArr, 4, doubleValue);

    std::cout << UNDERLINE << "\nafter iter :" << RESET << std::endl;
    iter(intArr, 4, print<int>);
    std::cout << std::endl;

    std::cout << BOLD << UNDERLINE << "\nTest string array" << RESET << std::endl;

    std::string strArr[] = {"Hello", "World", "!"};
    std::cout << UNDERLINE << "\nbefore iter :" << RESET << std::endl;
    iter(strArr, 3, print<std::string>);
    std::cout << std::endl;

    iter(strArr, 3, rot13);

    std::cout << UNDERLINE << "\nafter iter :" << RESET << std::endl;
    iter(strArr, 3, print<std::string>);
    std::cout << "\n" << std::endl;
    
}