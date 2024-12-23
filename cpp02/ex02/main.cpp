#include "Fixed.hpp"

int main(void)
{
    Fixed a(1.4f);
    Fixed b(2.6f);
    
    if (a > b)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    std::cout << a + b << std::endl;
    // Fixed const b(Fixed(5.05f) * Fixed(2));
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}