#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog &other): Animal(other) {
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
    if(this != &other)
        Animal::operator=(other);
    std::cout << "Dog assignment operator called." << std::endl;

    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor is called." << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog is barking" << std::endl;
}