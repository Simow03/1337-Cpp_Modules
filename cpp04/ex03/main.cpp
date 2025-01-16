#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    Character *original = new Character("original");
    original->equip(src->createMateria("ice"));
    Character *copy = new Character(*original);
    delete original;
    std::cout << "\n - - - copy ptr use() : - - - " << std::endl;
    copy->use(0, *bob);

    Character *full = new Character("full");
    for (int i = 0; i < 4; i++)
        full->equip(src->createMateria("ice"));

    full->unequip(0);
    full->equip(src->createMateria("cure"));


    std::cout << "\n - - - full ptr use() : - - - " << std::endl;
    full->use(0, *bob);

    delete copy;
    delete full;
    delete bob;
    delete me;
    delete src;

    return 0;
}