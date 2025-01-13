#include "WrongAnimal.hpp"
#include "Animal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "WrongAnimal";
    std::cout << CYAN << "WrongAnimal " << RESET << "default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    this->type = other.type;
    std::cout << CYAN << "WrongAnimal " << RESET << "copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
    if(this != &other)
        this->type = other.type;
    std::cout << CYAN << "WrongAnimal " << RESET << "operator called." << std::endl;

    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << CYAN << "WrongAnimal " << RESET << "destructor is called." << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << CYAN << "WrongAnimal " << RESET << "has no sound" << std::endl;
}

std::string WrongAnimal::getType() const{
    return this->type;
}
