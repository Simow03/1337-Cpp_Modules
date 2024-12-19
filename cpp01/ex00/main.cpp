#include "Zombie.hpp"

int main() {

    std::cout << "\n==== Creating a zombie on stack ====" << std::endl;
    randomChump("Stack Zombie");

    std::cout << "\n==== Creating a zombie on heap ====" << std::endl;
    Zombie* heapZombie = newZombie("Heap Zombie");

    heapZombie->announce();

    delete heapZombie;

    return 0;
}