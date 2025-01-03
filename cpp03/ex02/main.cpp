#include "ClapTrap.hpp"
#include "FragTrap.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main()
{
    std::cout << RED << UNDERLINE << BOLD << "\n\t Constructing:\n" << RESET << std::endl;
    FragTrap frag1("Destroyer");
    FragTrap frag2(frag1);

    std::cout << RED << UNDERLINE << BOLD << "\n\t Member functions:\n" << RESET << std::endl;
    frag1.attack("Enemy");
    frag1.takeDamage(25);
    frag1.beRepaired(8);
    frag1.highFivesGuys();
    frag1.takeDamage(115);
    frag1.beRepaired(5);
    frag1.attack("Enemy");
    frag1.takeDamage(10);

    std::cout << RED << UNDERLINE << BOLD << "\n\t Destructing:\n" << RESET << std::endl;

    return 0;
}