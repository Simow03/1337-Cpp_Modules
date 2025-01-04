#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

const std::string ORANGE = "\033[38;5;216m";
const std::string CYAN = "\033[38;5;117m";
const std::string RESET = "\033[0m";

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), name("Default")
{
    DiamondTrap::setAttributes("Default", FragTrap::getHitPoints(), ScavTrap::getEnergyPoints(), FragTrap::getAttackDamage());
    std::cout << ORANGE << "DiamondTrap " << RESET << "Default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &_name) : ClapTrap(_name + "_clap_name"), FragTrap(_name), ScavTrap(_name), name(_name)
{
    DiamondTrap::setAttributes(_name, FragTrap::getHitPoints(), ScavTrap::getEnergyPoints(), FragTrap::getAttackDamage());
    std::cout << ORANGE << "DiamondTrap " << RESET << getName() << " is being constructed .." << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    DiamondTrap::setAttributes(other.getName(), other.getHitPoints(), other.getEnergyPoints(), other.getAttackDamage());
    std::cout << ORANGE << "DiamondTrap " << RESET << "copy constructor is called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        DiamondTrap::setAttributes(other.getName(), other.getHitPoints(), other.getEnergyPoints(), other.getAttackDamage());
    }
    std::cout << ORANGE << "DiamondTrap " << RESET << "copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << ORANGE << "DiamondTrap " << RESET << getName() << " is getting destroyed !" << std::endl;
};

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
};

void DiamondTrap::whoAmI()
{
    std::cout << ORANGE << "DiamondTrap " << RESET << this->name << " A.K.A " << CYAN << "ClapTrap " << RESET << ClapTrap::getName() << std::endl;
};