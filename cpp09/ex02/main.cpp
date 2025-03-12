#include "PmergeMe.hpp"

void displayOutput(std::vector<int>numbers, std::vector<int>sortedVector, std::deque<int>sortedDeque) {

    std::cout << "Before: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\nAfter:  ";
    for (std::vector<int>::iterator it = sortedVector.begin(); it != sortedVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of   "
            << sortedVector.size() << " with std::vector :  "
            << ELAPSED_VECTOR << " us" << std::endl;
    std::cout << "Time to process a range of   "
            << sortedDeque.size() << " with std::deque  :  "
            << ELAPSED_DEQUE << " us" << std::endl;
}

int main(int ac, char **av) {

    if (ac < 2) {
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

    for (int i = 1; i < ac; i++)
        numbers.push_back(std::atoi(av[i]));

    std::vector<int> sortedVector = mergeInsertionSort(numbers);

    std::deque<int>numbersDeque(numbers.begin(), numbers.end()); 

    std::deque<int> sortedDeque = mergeInsertionSortDeque(numbersDeque);

    displayOutput(numbers, sortedVector, sortedDeque);
}