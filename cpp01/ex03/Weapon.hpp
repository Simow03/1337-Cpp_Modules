#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
private:
    std::string type;

public:
    Weapon( std::string weaponType );
    const std::string& getType( void ) const;
    void setType( const std::string& newType );
};

#endif