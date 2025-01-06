#include "ClapTrap.hpp"
#include "FragTrap.hpp"

const std::string PURPLE = "\033[38;5;183m";
const std::string RESET = "\033[0m";

FragTrap::FragTrap() : ClapTrap()
{
    this->name = "Default";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << PURPLE << "FragTrap " << RESET << "Default constructor called." << std::endl;
};

FragTrap::FragTrap(const std::string &_name) : ClapTrap(_name)
{
    this->name = _name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << PURPLE << "FragTrap " << RESET << this->name << " is being constructed .." << std::endl;
};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << PURPLE << "FragTrap " << RESET << "copy constructor is called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{

    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << PURPLE << "FragTrap " << RESET << "copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << PURPLE << "FragTrap " << RESET << this->name << " is getting destroyed !" << std::endl;
};

void FragTrap::attack(const std::string &target)
{
    if (energyPoints == 0)
    {
        std::cout << PURPLE << "FragTrap " << RESET << this->name << " Can't attack. No energy points left !" << std::endl;
        return;
    }

    if (hitPoints == 0)
    {
        std::cout << PURPLE << "FragTrap " << RESET << this->name << " Can't attack. No hit points left !" << std::endl;
        return;
    }

    energyPoints -= 1;

    std::cout << PURPLE << "FragTrap " << RESET
              << this->name << " attacks "
              << target << " causing "
              << this->attackDamage << " points of damage!"
              << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << PURPLE << "FragTrap " << RESET << this->name << " is requesting high fives from everyone!" << std::endl;
}