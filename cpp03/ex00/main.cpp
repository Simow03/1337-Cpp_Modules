#include "ClapTrap.hpp"

int main() {
    ClapTrap robot1("robot 1");
    ClapTrap robot2("robot 2");


    robot1.attack("robot2");
    robot2.takeDamage(20);
    robot2.takeDamage(10);
    robot2.takeDamage(10);
    robot2.attack("robot1");
}