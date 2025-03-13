#include "RPN.hpp"

int main(int ac, char **av) {

    if (ac != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    float result = calculateRPN(av[1]);

    std::cout << result << std::endl;
}