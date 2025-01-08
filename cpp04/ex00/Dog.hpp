#include "Animal.hpp"

class Dog : public Animal {

public:
    Dog();
    Dog(const Dog &other);
    Dog& operator=(const Dog &other);
    ~Dog();
    void makeSound();
};

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) {
    this->type = other.type;
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
    if(this != &other)
        this->type = other.type;
    std::cout << "Dog assignment operator called." << std::endl;

    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor is called." << std::endl;
}

void Dog::makeSound() {
    std::cout << "Dog is barking" << std::endl;
}