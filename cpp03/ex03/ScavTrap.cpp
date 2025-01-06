#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

const std::string YELLOW = "\033[93m";
const std::string RESET = "\033[0m";

ScavTrap::ScavTrap() : ClapTrap()
{
    this->name = "Default";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << YELLOW << "ScavTrap " << RESET << "Default constructor called." << std::endl;
};

ScavTrap::ScavTrap(const std::string &_name) : ClapTrap(_name)
{
    this->name = _name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << YELLOW << "ScavTrap " << RESET << this->name << " is being constructed .." << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << YELLOW << "ScavTrap " << RESET << "copy constructor is called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{

    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << YELLOW << "ScavTrap " << RESET << "copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << YELLOW << "ScavTrap " << RESET << this->name << " is getting destroyed !" << std::endl;
};

void ScavTrap::attack(const std::string &target)
{
    if (energyPoints == 0)
    {
        std::cout << YELLOW << "ScavTrap " << RESET << this->name << " Can't attack. No energy points left !" << std::endl;
        return;
    }

    if (hitPoints == 0)
    {
        std::cout << YELLOW << "ScavTrap " << RESET << this->name << " Can't attack. No hit points left !" << std::endl;
        return;
    }

    energyPoints -= 1;

    std::cout << YELLOW << "ScavTrap " << RESET
              << this->name << " attacks "
              << target << " causing "
              << this->attackDamage << " points of damage!"
              << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << YELLOW << "ScavTrap " << RESET << this->name << " is now in Gate keeper mode." << std::endl;
}