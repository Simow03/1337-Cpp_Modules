#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

const std::string ORANGE = "\033[38;5;216m";
const std::string CYAN = "\033[38;5;117m";
const std::string RESET = "\033[0m";

DiamondTrap::DiamondTrap() 
    : ClapTrap("Default_clap_name"), name("Default")
{
    this->FragTrap::hitPoints = 100;
    this->ScavTrap::energyPoints = 50;
    this->FragTrap::attackDamage = 30;
    ClapTrap::name = "Default_clap_name";
    std::cout << ORANGE << "DiamondTrap " << RESET << "Default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &_name) 
    : ClapTrap(_name + "_clap_name"), name(_name)
{
    this->FragTrap::hitPoints = 100;
    this->ScavTrap::energyPoints = 50;
    this->FragTrap::attackDamage = 30;
    ClapTrap::name = _name + "_clap_name";
    std::cout << ORANGE << "DiamondTrap " << RESET << this->name << " is being constructed .." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << ORANGE << "DiamondTrap " << RESET << "copy constructor is called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << ORANGE << "DiamondTrap " << RESET << "copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << ORANGE << "DiamondTrap " << RESET << this->name << " is getting destroyed !" << std::endl;
};

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
};

void DiamondTrap::whoAmI()
{
    std::cout << ORANGE << "DiamondTrap " << RESET << this->name << " A.K.A " << CYAN << "ClapTrap " << RESET << ClapTrap::name << std::endl;
};