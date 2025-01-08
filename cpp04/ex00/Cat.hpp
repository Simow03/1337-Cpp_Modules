#include "Animal.hpp"

class Cat : public Animal {

public:
    Cat();
    Cat(const Cat &other);
    Cat& operator=(const Cat &other);
    ~Cat();
    void makeSound();
};

Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) {
    this->type = other.type;
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
    if(this != &other)
        this->type = other.type;
    std::cout << "Cat assignment operator called." << std::endl;

    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor is called." << std::endl;
}

void Cat::makeSound() {
    std::cout << "Cat is meowing" << std::endl;
}