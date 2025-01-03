#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

const std::string YELLOW = "\033[93m";
const std::string RESET = "\033[0m";

ScavTrap::ScavTrap() : ClapTrap()
{
    setAttributes("Default", 100, 50, 20);
    std::cout << YELLOW << "ScavTrap " << RESET << "Default constructor called." << std::endl;
};

ScavTrap::ScavTrap(const std::string &_name) : ClapTrap(_name)
{
    setAttributes(_name, 100, 50, 20);
    std::cout << YELLOW << "ScavTrap " << RESET << getName() << " is being constructed .." << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    setAttributes(other.getName(), other.getHitPoints(), other.getEnergyPoints(), other.getAttackDamage());
    std::cout << YELLOW << "ScavTrap " << RESET << "copy constructor is called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{

    if (this != &other)
    {
        setAttributes(other.getName(), other.getHitPoints(), other.getEnergyPoints(), other.getAttackDamage());
    }
    std::cout << YELLOW << "ScavTrap " << RESET << "copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << YELLOW << "ScavTrap " << RESET << getName() << " is getting destroyed !" << std::endl;
};

void ScavTrap::attack(const std::string &target)
{
    if (getEnergyPoints() == 0)
    {
        std::cout << YELLOW << "ScavTrap " << RESET << getName() << " Can't attack. No energy points left !" << std::endl;
        return;
    }

    if (getHitPoints() == 0)
    {
        std::cout << YELLOW << "ScavTrap " << RESET << getName() << " Can't attack. No hit points left !" << std::endl;
        return;
    }

    setAttributes(getName(), getHitPoints(), getEnergyPoints() - 1, getAttackDamage());

    std::cout << YELLOW << "ScavTrap " << RESET
              << getName() << " attacks "
              << target << " causing "
              << getAttackDamage() << " points of damage!"
              << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << YELLOW << "ScavTrap " << RESET << getName() << " is now in Gate keeper mode." << std::endl;
}