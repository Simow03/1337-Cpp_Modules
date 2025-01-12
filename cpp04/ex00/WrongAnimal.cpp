#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    this->type = other.type;
    std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
    if(this != &other)
        this->type = other.type;
    std::cout << "WrongAnimal assignment operator called." << std::endl;

    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor is called." << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal has no sound" << std::endl;
}

std::string WrongAnimal::getType() const{
    return this->type;
}
