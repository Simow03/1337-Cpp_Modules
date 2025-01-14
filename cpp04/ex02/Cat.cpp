#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain()) {
    this->type = "Cat";
    std::cout << YELLOW << "Cat " << RESET << "default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << YELLOW << "Cat " << RESET << "assignment operator called." << std::endl;

    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << YELLOW << "Cat " << RESET << "destructor is called." << std::endl;
}

void Cat::makeSound() const{
    std::cout << YELLOW << "Cat " << RESET << "is meowing" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}