#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie( std::string zombieName ) : name(zombieName) {}

Zombie::~Zombie() {
    std::cout << name << ": Being destroyed..." << std::endl;
}

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string newName ) {
    name = newName;
}