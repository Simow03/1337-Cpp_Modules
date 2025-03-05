# include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main() {
    std::cout << BOLD << UNDERLINE << "\nSpan calculator Test:" << RESET << std::endl;
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        try {
            std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    std::cout << BOLD << UNDERLINE << "\nLarge Number Test (10,000 elements):" << RESET << std::endl;
    {
        const int LARGE_SIZE = 10000;
        Span largeSpan(LARGE_SIZE);

        std::srand(time(NULL));
        std::vector<int> randomNumbers(LARGE_SIZE);
        for (int i = 0; i < LARGE_SIZE; ++i) {
            randomNumbers[i] = std::rand();
        }

        try {
            largeSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());

            std::cout << "Large Span - Shortest: " << largeSpan.shortestSpan() << std::endl;
            std::cout << "Large Span - Longest: " << largeSpan.longestSpan() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error in large number test: " << e.what() << std::endl;
        }
    }

    std::cout << BOLD << UNDERLINE << "\nError Case Tests:" << RESET << std::endl;
    {
        try {
            Span sp(3);
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4);
        } catch (const std::exception& e) {
            std::cout << "Overfill Test : " << e.what() << std::endl;
        }
        try {
            Span sp(2);
            sp.addNumber(5);
            sp.shortestSpan();
        } catch (const std::exception& e) {
            std::cout << "Insufficient Span Test : " << e.what() << std::endl;
        }
    }
}