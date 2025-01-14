#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void f()
{
    system("leaks brain");
}

int main()
{
    // atexit(f);
    {
        std::cout << RED << UNDERLINE << BOLD << "\n\tTest Deep Copy:\n"
                  << RESET << std::endl;

        std::cout << UNDERLINE << "=== Test Dog using copy constructor : ===" << RESET << std::endl;

        Dog firstDog;
        firstDog.getBrain()->setIdea(0, "I eat meat!");

        Dog copyDog(firstDog);
        std::cout << "firstDog idea : " << firstDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "copyDog idea : " << copyDog.getBrain()->getIdea(0) << std::endl;

        firstDog.getBrain()->setIdea(0, "Nevermind . . . I like bones!");
        std::cout << "After modifying firstDog idea : firstDog : " << firstDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "After modifying firstDog idea : copyDog : " << copyDog.getBrain()->getIdea(0) << std::endl;

        std::cout << std::endl;
        std::cout << UNDERLINE << "=== Test Cat using assignment operator : ===" << RESET << std::endl;

        Cat firstCat;
        firstCat.getBrain()->setIdea(0, "I eat fish!");

        Cat assignCat;
        assignCat = firstCat;
        std::cout << "firstCat idea : " << firstCat.getBrain()->getIdea(0) << std::endl;
        std::cout << "assignCat idea : " << assignCat.getBrain()->getIdea(0) << std::endl;

        firstCat.getBrain()->setIdea(0, "NO! I like chasing laser pointers");
        std::cout << "After modifying firstCat idea : firstCat : " << firstCat.getBrain()->getIdea(0) << std::endl;
        std::cout << "After modifying firstCat idea : assignCat : " << assignCat.getBrain()->getIdea(0) << std::endl;

        std::cout << std::endl;
        std::cout << UNDERLINE << "=== Cleaning up objects : ===" << RESET << std::endl;
    }
    {
        std::cout << RED << UNDERLINE << BOLD << "\n\tTest Animal Array:\n"
                  << RESET << std::endl;

        const int arraySize = 6;
        Animal *animals[arraySize];

        std::cout << std::endl;
        std::cout << UNDERLINE << "=== Fill array : ===" << RESET << std::endl;
        for (int i = 0; i < arraySize; i++)
        {
            if (i < arraySize / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        std::cout << std::endl;
        std::cout << UNDERLINE << "=== Test makeSound() : ===" << RESET << std::endl;
        for (int i = 0; i < arraySize; i++)
            animals[i]->makeSound();

        std::cout << std::endl;
        std::cout << UNDERLINE << "=== Cleaning up array : ===" << RESET << std::endl;
        for (int i = 0; i < arraySize; i++)
            delete animals[i];
    }
    return 0;
}