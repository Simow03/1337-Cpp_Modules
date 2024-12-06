#include "HumanA.hpp"

HumanA::HumanA( std::string newName, Weapon& newWeapon ) : name(newName), weapon(newWeapon) {};

void HumanA::attack( void ) const{
    std::cout << name
            << " attacks with their "
            << weapon.getType()
            << std::endl;
}