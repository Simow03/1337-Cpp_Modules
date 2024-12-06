#include "Weapon.hpp"

Weapon::Weapon( std::string weaponType ) : type(weaponType){};

const std::string& Weapon::getType( void ) const{
    return type;
}
void Weapon::setType( const std::string& newType ) {
    type = newType;
}