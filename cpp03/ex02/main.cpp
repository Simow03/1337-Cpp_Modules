#include "ClapTrap.hpp"
#include "FragTrap.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main()
{
    std::cout << RED << UNDERLINE << BOLD << "\n\tConstructing:\n" << RESET << std::endl;
    FragTrap frag1("FT02-1");

    std::cout << RED << UNDERLINE << BOLD << "\n\tMember functions:\n" << RESET << std::endl;
    frag1.attack("FT02-2");
    frag1.takeDamage(25);
    frag1.beRepaired(8);
    frag1.takeDamage(115);
    frag1.beRepaired(5);
    frag1.attack("FT02-2");
    frag1.takeDamage(10);
    frag1.highFivesGuys();

    std::cout << RED << UNDERLINE << BOLD << "\n\tDestructing:\n" << RESET << std::endl;

    return 0;
}