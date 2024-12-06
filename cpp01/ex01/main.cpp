#include "Zombie.hpp"
#include <cstdlib>

int main( void ) {

    int size = 5;

    Zombie* smallHorde = zombieHorde(size, "Little Zombie");
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << " : ";
        smallHorde[i].announce();
    }

    delete[] smallHorde;

    size = 25;

    Zombie* largeHorde = zombieHorde(size, "Big Zombie");

    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << " : ";
        largeHorde[i].announce();
    }

    delete[] largeHorde;

    size = -1;

    Zombie* negativeHorde = zombieHorde(size, "Negative Zombie");
    if (negativeHorde == NULL) {
        std::cout << "Negative-sized horde returned NULL!" << std::endl;
    }
}
