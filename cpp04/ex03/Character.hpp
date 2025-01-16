#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private :
    std::string name;
    static const int size = 4;
    AMateria* inventory[size];
    AMateria* droppedMaterias[size];

public :
    Character();
    Character(std::string const &name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

};

#endif