#include <iostream>

#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

int main() {

    Data original(213, 'A', true);

    const std::string RESET = "\033[0m";
    const std::string GREEN = "\033[32m";
    const std::string CYAN = "\033[36m";
    const std::string YELLOW = "\033[33m";
    const std::string RED = "\033[31m";
    const std::string UNDERLINE = "\033[4m";

    std::cout << CYAN << UNDERLINE << "Original pointer:" << RESET << " " << &original << std::endl;
    std::cout << YELLOW << UNDERLINE << "Original data:" << RESET
              << " id = " << original.id << ", initial = " << original.initial 
              << ", isHuman = " << original.isHuman << std::endl;

    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << CYAN << UNDERLINE << "Serialized value:" << RESET << " " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << CYAN << UNDERLINE << "Deserialized pointer:" << RESET << " " << deserialized << std::endl;
    std::cout << YELLOW << UNDERLINE << "Deserialized data:" << RESET
              << " id = " << deserialized->id << ", initial = " << deserialized->initial
              << ", isHuman = " << deserialized->isHuman << std::endl;

    if (&original == deserialized)
        std::cout << GREEN << UNDERLINE << "SUCCESS:" << RESET << " Pointers are the same!" << std::endl;
    else
        std::cout << RED << UNDERLINE << "ERROR:" << RESET << " Pointers don't match!" << std::endl;

    return 0;
}