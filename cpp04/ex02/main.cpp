#include "Animal.hpp"
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

        std::cout << UNDERLINE << "=== Using Animal pointers : ===" << RESET << std::endl;
        Animal *i = new Cat();
        Animal *j = new Dog();

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