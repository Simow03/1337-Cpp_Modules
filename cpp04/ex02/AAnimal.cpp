#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Abstract Animal") {
    std::cout << CYAN << "AAnimal " << RESET << "default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type) {
    std::cout << CYAN << "AAnimal " << RESET << "copy constructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other) {
    if(this != &other)
        this->type = other.type;
    std::cout << CYAN << "AAnimal " << RESET << "assignment operator called." << std::endl;

    return *this;
}

AAnimal::~AAnimal() {
    std::cout << CYAN << "AAnimal " << RESET << "destructor is called." << std::endl;
}

std::string AAnimal::getType() const{
    return this->type;
}
