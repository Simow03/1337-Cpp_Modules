#ifndef ZOMBIE_HPP
#define ZPMBIE_HPP

#include <iostream>

class Zombie {

private:
    std::string name;

public:

    Zombie( std::string zombieName );

    void announce( void );

    ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif