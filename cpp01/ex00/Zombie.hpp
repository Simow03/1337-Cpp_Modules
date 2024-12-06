#include <iostream>

class Zombie {

private:
    std::string name;

public:

    Zombie( std::string zombieName );

    void announce( void ) {
        std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }

    ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );