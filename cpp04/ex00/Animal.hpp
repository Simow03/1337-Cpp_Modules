#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string BOLD = "\033[1m";
const std::string GREEN = "\033[38;5;121m";
const std::string CYAN = "\033[38;5;117m";
const std::string YELLOW = "\033[93m";
const std::string BLUE = "\033[38;5;69m";
const std::string PURPLE = "\033[38;5;183m";
const std::string UNDERLINE = "\033[4m";

class Animal {

protected:
    std::string type;

public :
    Animal();
    Animal(const Animal &other);
    Animal& operator=(const Animal &other);
    virtual ~Animal();
    virtual void makeSound() const;
    std::string getType(void) const;
};

#endif