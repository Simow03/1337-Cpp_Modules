#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap::ScavTrap(const std::string &name);
    ScavTrap::ScavTrap(const ScavTrap &other);
    ScavTrap &ScavTrap::operator=(ScavTrap &other);
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate(void);
};

#endif