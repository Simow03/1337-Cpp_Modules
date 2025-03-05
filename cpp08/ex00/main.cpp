# include "easyfind.hpp"
#include <vector>
#include <list>

const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main() {

    std::cout << BOLD << UNDERLINE << "\nTest using vector :" << RESET << std::endl;
    
    std::vector<int> vec;
    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
    }
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Occurrence was found ! : " << *it << std::endl;
    }
    catch (std::exception&) {
        std::cout << "Exception caught : occurence not found !\n" << std::endl;
    }

    std::cout << BOLD << UNDERLINE << "\nTest using list :" << RESET << std::endl;

    std::list<int> lst;
    for (int i = -5; i < 0; i++) {
        lst.push_back(i);
    }
    try {
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "Occurrence was found ! : " << *it << std::endl;
    }
    catch (std::exception&) {
        std::cout << "Exception caught : occurence not found !\n" << std::endl;
    }
}