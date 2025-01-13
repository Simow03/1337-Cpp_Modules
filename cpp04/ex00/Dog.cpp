#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << BLUE << "Dog " << RESET << "default constructor called." << std::endl;
}

Dog::Dog(const Dog &other): Animal(other) {
    std::cout << BLUE << "Dog " << RESET << "copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
    if(this != &other)
        Animal::operator=(other);
    std::cout << BLUE << "Dog " << RESET << "assignment operator called." << std::endl;

    return *this;
}

Dog::~Dog() {
    std::cout << BLUE << "Dog " << RESET << "destructor is called." << std::endl;
}

void Dog::makeSound() const{
    std::cout << BLUE << "Dog " << RESET << "is barking" << std::endl;
}