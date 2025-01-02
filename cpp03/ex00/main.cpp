#include "ClapTrap.hpp"

int main() {
    ClapTrap default_robot;
    ClapTrap robot("R2D2");
    ClapTrap robot_copy(robot);
    ClapTrap another_robot;
    another_robot = robot;
    
    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);

    return 0;
}