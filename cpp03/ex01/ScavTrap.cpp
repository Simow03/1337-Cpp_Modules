#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
{
    setAttributes("Default", 100, 50, 20);
    std::cout << "ScavTrap Default constructor called." << std::endl;
};

ScavTrap::ScavTrap(const std::string &_name)
{
    setAttributes(_name, 100, 50, 20);
    std::cout << "ScavTrap " << getName() << " is being constructed .." << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other)
{
    setAttributes(other.getName(), other.getHitPoints(), other.getEnergyPoints(), other.getAttackDamage());
    std::cout << "ScavTrap copy constructor is called." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &other)
{

    if (this != &other)
    {
        setAttributes(other.getName(), other.getHitPoints(), other.getEnergyPoints(), other.getAttackDamage());
    }
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " is getting destroyed !" << std::endl;
};

void ScavTrap::attack(const std::string &target)
{
    if (getEnergyPoints() == 0)
    {
        std::cout << "ScavTrap " << getName() << " Can't attack. No energy points left !" << std::endl;
        return;
    }

    if (getHitPoints() == 0)
    {
        std::cout << "ScavTrap " << getName() << " Can't attack. No hit points left !" << std::endl;
        return;
    }

    setAttributes(getName(), getHitPoints(), getEnergyPoints() - 1, getAttackDamage());

    std::cout << "ScavTrap "
              << getName() << " attacks "
              << target << " causing "
              << getAttackDamage() << " points of damage!"
              << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}