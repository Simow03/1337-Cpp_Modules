#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain(){
    std::cout << MAGENTA << "Brain " << RESET << "default constructor called." << std::endl;
}

Brain::Brain(const Brain& other){
    std::copy(other.ideas, other.ideas + 100, this->ideas);
    std::cout << MAGENTA << "Brain " << RESET << "copy constructor called." << std::endl;
}
Brain& Brain::operator=(const Brain& other){
    if(this != &other)
        std::copy(other.ideas, other.ideas + 100, this->ideas);

    std::cout << MAGENTA << "Brain " << RESET << "assignment operator called." << std::endl;

    return *this;
}
Brain::~Brain(){
    std::cout << MAGENTA << "Brain " << RESET << "destructor is called." << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "Invalid index !";
}