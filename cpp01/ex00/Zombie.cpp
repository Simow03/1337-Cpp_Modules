#include "Zombie.hpp"

Zombie::Zombie( std::string zombieName ) : name(zombieName) {}

Zombie::~Zombie() {
    std::cout << name << ": Being destroyed..." << std::endl;
}