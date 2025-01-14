#include "Animal.hpp"

Animal::Animal() : type("Abstract Animal") {
    std::cout << CYAN << "Animal " << RESET << "default constructor called." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << CYAN << "Animal " << RESET << "copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
    if(this != &other)
        this->type = other.type;
    std::cout << CYAN << "Animal " << RESET << "assignment operator called." << std::endl;

    return *this;
}

Animal::~Animal() {
    std::cout << CYAN << "Animal " << RESET << "destructor is called." << std::endl;
}

std::string Animal::getType() const{
    return this->type;
}
