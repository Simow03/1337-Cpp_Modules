#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
#include "Colors.hpp"

class AAnimal {

protected:
    std::string type;

public :
    AAnimal();
    AAnimal(const AAnimal &other);
    AAnimal& operator=(const AAnimal &other);
    virtual ~AAnimal();
    virtual void makeSound(void) const = 0;
    std::string getType(void) const;
};

#endif