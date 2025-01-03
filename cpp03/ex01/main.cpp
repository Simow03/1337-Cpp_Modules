#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main()
{
    std::cout << RED << UNDERLINE << BOLD << "\n\t Constructing:\n" << RESET << std::endl;
    ScavTrap scav1("Guardian");
    ScavTrap scav2(scav1);

    std::cout << RED << UNDERLINE << BOLD << "\n\t Member functions:\n" << RESET << std::endl;
    scav1.attack("Enemy");
    scav1.takeDamage(30);
    scav1.beRepaired(15);
    scav1.guardGate();
    scav1.takeDamage(101);
    scav1.beRepaired(5);
    scav1.attack("Enemy");
    scav1.takeDamage(8);

    std::cout << RED << UNDERLINE << BOLD << "\n\t Destructing:\n" << RESET << std::endl;

    return 0;
}