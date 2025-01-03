#include "ClapTrap.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main() {

    std::cout << RED << UNDERLINE << BOLD << "\n\t Constructing:\n" << RESET << std::endl;
    ClapTrap default_robot;
    ClapTrap robot("R2D2");
    ClapTrap robot_copy(robot);
    ClapTrap another_robot;
    another_robot = robot;
    
    std::cout << RED << UNDERLINE << BOLD << "\n\t Member functions:\n" << RESET << std::endl;
    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(12);
    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);

    std::cout << RED << UNDERLINE << BOLD << "\n\t Destructing:\n" << RESET << std::endl;

    return 0;
}