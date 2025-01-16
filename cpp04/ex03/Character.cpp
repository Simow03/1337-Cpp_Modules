#include "Character.hpp"

Character::Character() : name("npc")
{
    for (int i = 0; i < size; i++)
    {
        inventory[i] = NULL;
        droppedMaterias[i] = NULL;
    }
};

Character::Character(std::string const &_name) : name(_name)
{
    for (int i = 0; i < size; i++)
    {
        inventory[i] = NULL;
        droppedMaterias[i] = NULL;
    }
};

Character::Character(const Character &other) : name(other.name)
{
    for (int i = 0; i < size; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;

        droppedMaterias[i] = NULL;
    }
}

Character &Character::operator=(const Character &other)
{

    if (this != &other)
    {
        for (int i = 0; i < size; i++)
        {
            delete inventory[i];
            delete droppedMaterias[i];
            inventory[i] = NULL;
            droppedMaterias[i] = NULL;
        }

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

    for (int i = 0; i < size; i++)
        delete droppedMaterias[i];
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

    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < size && inventory[idx])
    {
        for (int i = 0; i < size; i++)
        {
            if (!droppedMaterias[i])
            {
                droppedMaterias[i] = inventory[idx];
                inventory[idx] = NULL;
                return ;
            }
        }
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < size && inventory[idx])
        inventory[idx]->use(target);
}