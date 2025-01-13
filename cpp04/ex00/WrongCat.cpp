#include "WrongCat.hpp"
#include "Animal.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << YELLOW << "WrongCat " << RESET << "default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << YELLOW << "WrongCat " << RESET << "copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
    if(this != &other)
        WrongAnimal::operator=(other);
    std::cout << YELLOW << "WrongCat " << RESET << "assignment operator called." << std::endl;

    return *this;
}

WrongCat::~WrongCat() {
    std::cout << YELLOW << "WrongCat " << RESET << "destructor is called." << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << YELLOW << "WrongCat " << RESET << "is meowing" << std::endl;
}
