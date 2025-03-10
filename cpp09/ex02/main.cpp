#include "PmergeMe.hpp"

int main(int ac, char **av) {

    if (ac < 3) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    for (int i = 1; i < ac; i++) {

        if (!isPositiveInteger(av[i])) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    std::vector<int> numbers;

    for (int i = 0; i < ac; i++)
        numbers.push_back(std::atoi(av[i]));

    std::vector<int> sorted = mergeInsertionSort(numbers);

    displayOutput();
}