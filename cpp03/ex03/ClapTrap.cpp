#include "ClapTrap.hpp"

const std::string CYAN = "\033[38;5;117m";
const std::string RESET = "\033[0m";

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << CYAN << "ClapTrap " << RESET << "Default constructor called." << std::endl;
};

ClapTrap::ClapTrap(const std::string &_name)
    : name(_name),
      hitPoints(10),
      energyPoints(10),
      attackDamage(0)
{
    std::cout << CYAN << "ClapTrap " << RESET << name << " is being constructed .." << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other)
    : name(other.name), hitPoints(other.hitPoints),
      energyPoints(other.energyPoints),
      attackDamage(other.attackDamage)
{
    std::cout << CYAN << "ClapTrap " << RESET << "copy constructor is called." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{

    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << CYAN << "ClapTrap " << RESET << "copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << CYAN << "ClapTrap " << RESET << name << " is getting destroyed !" << std::endl;
};

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints == 0)
    {
        std::cout << CYAN << "ClapTrap " << RESET << name << " Can't attack. No energy points left !" << std::endl;
        return;
    }

    if (hitPoints == 0)
    {
        std::cout << CYAN << "ClapTrap " << RESET << name << " Can't attack. No hit points left !" << std::endl;
        return;
    }

    energyPoints--;

    std::cout << CYAN << "ClapTrap " << RESET
              << name << " attacks "
              << target << " causing "
              << attackDamage << " points of damage!"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << CYAN << "ClapTrap " << RESET << name << " is already defeated!" << std::endl;
        return;
    }

    if (amount >= hitPoints)
        hitPoints = 0;

    else
    {
        hitPoints -= amount;
    }
    std::cout << CYAN << "ClapTrap " << RESET
              << name << " took "
              << amount << " points of damage! Hit points remaining : "
              << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints == 0)
    {
        std::cout << CYAN << "ClapTrap " << RESET << name << " Can't be repaired. No energy points left !" << std::endl;
        return;
    }

    if (hitPoints == 0)
    {
        std::cout << CYAN << "ClapTrap " << RESET << name << " Can't be repaired. No hit points left !" << std::endl;
        return;
    }

    energyPoints--;
    hitPoints += amount;
    std::cout << CYAN << "ClapTrap " << RESET << name
              << " is repairing itself for " << amount
              << ". Current hit points : " << hitPoints
              << std::endl;
}
