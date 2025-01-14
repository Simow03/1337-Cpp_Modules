#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void f()
{
    system("leaks abstractClass");
}

int main()
{
    // atexit(f);
    {
        std::cout << RED << UNDERLINE << BOLD << "\n\tAbstract Class:\n"
                  << RESET << std::endl;

        std::cout << UNDERLINE << "=== Using AAnimal pointers : ===" << RESET << std::endl;
        AAnimal *i = new Cat();
        AAnimal *j = new Dog();

        std::cout << "Calling getType() using Cat pointer : " << std::endl;
        std::cout << i->getType() << std::endl;
        std::cout << "Calling getType() using Dog pointer : " << std::endl;
        std::cout << j->getType() << std::endl;
        std::cout << "Calling makeSound() using Cat pointer : " << std::endl;
        i->makeSound();
        std::cout << "Calling makeSound() using Dog pointer : " << std::endl;
        j->makeSound();

        std::cout << std::endl;
        std::cout << UNDERLINE << "=== Cleaning up Pointers : ===" << RESET << std::endl;
        delete i;
        delete j;

    }
    return 0;
}