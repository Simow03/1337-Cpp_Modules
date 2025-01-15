#include "Character.hpp"
#include <algorithm>

Character::Character() : name("Default")
{
    for (int i = 0; i < size; i++)
        inventory[i] = NULL;
};

Character::Character(std::string const &_name) : name(_name)
{
    for (int i = 0; i < size; i++)
        inventory[i] = NULL;
};

Character::Character(const Character &other) : name(other.name)
{
    for (int i = 0; i < size; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &other)
{

    if (this != &other)
    {
        for (int i = 0; i < size; i++)
            delete inventory[i];

        this->name = other.name;

        for (int i = 0; i < size; i++)
        {
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }

    return *this;
}

Character::~Character()
{
    for (int i = 0; i < size; i++)
        delete inventory[i];
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < size; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < size && inventory[idx])
        inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < size && inventory[idx])
        inventory[idx]->use(target);
}