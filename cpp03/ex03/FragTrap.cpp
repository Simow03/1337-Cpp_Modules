#include "ClapTrap.hpp"
#include "FragTrap.hpp"

const std::string PURPLE = "\033[38;5;183m";
const std::string RESET = "\033[0m";

FragTrap::FragTrap() : ClapTrap()
{
    setAttributes("Default", 100, 100, 30);
    std::cout << PURPLE << "FragTrap " << RESET << "Default constructor called." << std::endl;
};

FragTrap::FragTrap(const std::string &_name) : ClapTrap(_name)
{
    setAttributes(_name, 100, 100, 30);
    std::cout << PURPLE << "FragTrap " << RESET << getName() << " is being constructed .." << std::endl;
};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    setAttributes(other.getName(), other.getHitPoints(), other.getEnergyPoints(), other.getAttackDamage());
    std::cout << PURPLE << "FragTrap " << RESET << "copy constructor is called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{

    if (this != &other)
    {
        setAttributes(other.getName(), other.getHitPoints(), other.getEnergyPoints(), other.getAttackDamage());
    }
    std::cout << PURPLE << "FragTrap " << RESET << "copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << PURPLE << "FragTrap " << RESET << getName() << " is getting destroyed !" << std::endl;
};

void FragTrap::attack(const std::string &target)
{
    if (getEnergyPoints() == 0)
    {
        std::cout << PURPLE << "FragTrap " << RESET << getName() << " Can't attack. No energy points left !" << std::endl;
        return;
    }

    if (getHitPoints() == 0)
    {
        std::cout << PURPLE << "FragTrap " << RESET << getName() << " Can't attack. No hit points left !" << std::endl;
        return;
    }

    setAttributes(getName(), getHitPoints(), getEnergyPoints() - 1, getAttackDamage());

    std::cout << PURPLE << "FragTrap " << RESET
              << getName() << " attacks "
              << target << " causing "
              << getAttackDamage() << " points of damage!"
              << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << PURPLE << "FragTrap " << RESET << getName() << " is requesting high fives from everyone!" << std::endl;
}