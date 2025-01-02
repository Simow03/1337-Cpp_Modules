#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called." << std::endl;
};

ClapTrap::ClapTrap(const std::string &_name)
    : name(_name),
      hitPoints(10),
      energyPoints(10),
      attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is being constructed .." << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other)
    : name(other.name), hitPoints(other.hitPoints),
      energyPoints(other.energyPoints),
      attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap copy constructor is called." << std::endl;
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
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " is getting destroyed !" << std::endl;
};

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " Can't attack. No energy points left !" << std::endl;
        return;
    }

    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " Can't attack. No hit points left !" << std::endl;
        return;
    }

    this->energyPoints--;

    std::cout << "ClapTrap "
              << name << " attacks "
              << target << " causing "
              << attackDamage << " points of damage!"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already defeated!" << std::endl;
        return;
    }

    if (amount >= hitPoints)
        hitPoints = 0;

    else
    {
        hitPoints -= amount;
    }
    std::cout << "ClapTrap "
              << this->name << " took "
              << amount << " points of damage! Hit points remaining : "
              << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " Can't be repaired. No energy points left !" << std::endl;
        return;
    }

    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " Can't be repaired. No hit points left !" << std::endl;
        return;
    }

    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name
              << " is repairing itself for " << amount
              << ". Current hit points : " << hitPoints
              << std::endl;
}
