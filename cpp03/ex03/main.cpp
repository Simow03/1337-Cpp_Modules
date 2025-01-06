#include "DiamondTrap.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main()
{
    std::cout << RED << UNDERLINE << BOLD << "\n\tConstructing:\n"
              << RESET << std::endl;
    DiamondTrap diamond("Hybrid");

    std::cout << RED << UNDERLINE << BOLD << "\n\tMember functions:\n"
              << RESET << std::endl;
    diamond.attack("Enemy");
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();

    std::cout << RED << UNDERLINE << BOLD << "\n\tDestructing:\n"
              << RESET << std::endl;

    return 0;
}
