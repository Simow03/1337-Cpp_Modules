#include "ClapTrap.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main() {

    std::cout << RED << UNDERLINE << BOLD << "\n\tConstructing:\n" << RESET << std::endl;
    ClapTrap default_robot;
    ClapTrap robot("CT00-1");
    ClapTrap robot_copy(robot);
    ClapTrap another_robot;
    another_robot = robot;
    
    std::cout << RED << UNDERLINE << BOLD << "\n\tMember functions:\n" << RESET << std::endl;
    robot.attack("CT00-2");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(12);
    robot.attack("CT00-2");
    robot.takeDamage(5);
    robot.beRepaired(3);

    std::cout << RED << UNDERLINE << BOLD << "\n\tDestructing:\n" << RESET << std::endl;

    return 0;
}