#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << YELLOW << "Cat " << RESET << "default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
    if(this != &other)
        Animal::operator=(other);
    std::cout << YELLOW << "Cat " << RESET << "assignment operator called." << std::endl;

    return *this;
}

Cat::~Cat() {
    std::cout << YELLOW << "Cat " << RESET << "destructor is called." << std::endl;
}

void Cat::makeSound() const{
    std::cout << YELLOW << "Cat " << RESET << "is meowing" << std::endl;
}