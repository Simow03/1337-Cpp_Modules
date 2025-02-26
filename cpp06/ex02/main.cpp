#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main() {

    for (int i = 0; i < 5; i++) {
        Base* obj = Base::generate();
        std::cout << BOLD << UNDERLINE << "Test " << i + 1 << ":" << RESET << std::endl;
        std::cout << "  Using pointer: ";
        Base::identify(obj);
        std::cout << "  Using reference: ";
        Base::identify(*obj);
        delete obj;
        std::cout << std::endl;
    }
    return 0;
}
