#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void f()
{
    system("leaks polymorphism");
}

int main()
{
    atexit(f);
    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        std::cout << meta->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }
    {
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i = new WrongCat();

        std::cout << meta->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        meta->makeSound();

        delete meta;
        delete i;
    }

    return 0;
}