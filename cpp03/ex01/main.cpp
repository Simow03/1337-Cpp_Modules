#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav1("Guardian");
    ScavTrap scav2(scav1);

    scav1.attack("Enemy");
    scav1.takeDamage(30);
    scav1.beRepaired(15);
    scav1.guardGate();



    return 0;
}