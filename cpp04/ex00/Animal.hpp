#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal {

protected:
    std::string type;

public :
    Animal();
    Animal(const Animal &other);
    Animal& operator=(const Animal &other);
    ~Animal();
    virtual void makeSound();
    std::string getType(void) const;
};

Animal::Animal() {
    this->type = "Animal";
    std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal &other) {
    this->type = other.type;
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
    if(this != &other)
        this->type = other.type;
    std::cout << "Animal assignment operator called." << std::endl;

    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor is called." << std::endl;
}

void Animal::makeSound() {
    std::cout << "Animal has no sound" << std::endl;
}

std::string Animal::getType() const{
    return this->type;
}

#endif