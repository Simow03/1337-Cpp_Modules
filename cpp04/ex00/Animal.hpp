#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Colors.hpp"

class Animal {

protected:
    std::string type;

public :
    Animal();
    Animal(const Animal &other);
    Animal& operator=(const Animal &other);
    virtual ~Animal();
    virtual void makeSound(void) const;
    std::string getType(void) const;
};

#endif