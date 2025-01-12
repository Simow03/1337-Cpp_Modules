#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
    if(this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat assignment operator called." << std::endl;

    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor is called." << std::endl;
}
