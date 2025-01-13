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
    // atexit(f);
    {
        std::cout << RED << UNDERLINE << BOLD << "\n\tFirst Scope:\n" << RESET << std::endl;

        std::cout << UNDERLINE << "=== Initiating Animal Classes : ===" << RESET << std::endl;
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        std::cout << std::endl;
        std::cout << UNDERLINE << "=== Testing getType() : ===" << RESET << std::endl;
        std::cout << "Animal pointer type : " << meta->getType() << std::endl;
        std::cout << "Dog pointer type : " << j->getType() << std::endl;
        std::cout << "Cat pointer type : " << i->getType() << std::endl;
        std::cout << std::endl;
        std::cout<< UNDERLINE << "=== Testing makeSound() ===" << RESET << std::endl;
        std::cout << "Calling makeSound of Cat pointer : " << std::endl;
        i->makeSound();
        std::cout << "Calling makeSound of Dog pointer : " << std::endl;
        j->makeSound();
        std::cout << "Calling makeSound of Animal pointer : " << std::endl;
        meta->makeSound();

        std::cout << std::endl;
        std::cout << UNDERLINE << "=== Cleaning up objects : ===" << RESET << std::endl;
        delete meta;
        delete j;
        delete i;
    }
    {
        std::cout << RED << UNDERLINE << BOLD << "\n\tSecond Scope:\n" << RESET << std::endl;

        std::cout << UNDERLINE << "=== Initiating WrongAnimal Classes : ===" << RESET << std::endl;
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i = new WrongCat();

        std::cout << std::endl;
        std::cout << UNDERLINE << "=== Testing getType() : ===" << RESET << std::endl;
        std::cout << "WrongAnimal pointer type : " << meta->getType() << std::endl;
        std::cout<< "WrongCat pointer type : " << i->getType() << std::endl;
        std::cout << std::endl;
        std::cout<< UNDERLINE << "=== Testing makeSound() ===" << RESET << std::endl;
        std::cout << "Calling makeSound of WrongAnimal pointer : " << std::endl;
        meta->makeSound();
        std::cout << "Calling makeSound of WrongCat pointer : " << std::endl;
        i->makeSound();

        std::cout << std::endl;
        std::cout << UNDERLINE << "=== Cleaning up objects : ===" << RESET << std::endl;
        delete meta;
        delete i;
    }

    return 0;
}