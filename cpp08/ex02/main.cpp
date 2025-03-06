#include "MutantStack.hpp"
#include <list>

const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

void testMutantStack() {

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Forward Iteration:" << std::endl;
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << ", ";
        ++it;
    }
    std::cout << std::endl;

    std::stack<int> s(mstack);

}

void testListContainer() {

    std::list<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << "Top element: " << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();

    std::cout << "Forward Iteration:" << std::endl;
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << ", ";
        ++it;
    }
    std::cout << "\n" << std::endl;
}

int main() {
    std::cout << BOLD << UNDERLINE << "\nMutantStack Test:" << RESET << std::endl;
    testMutantStack();
    std::cout << BOLD << UNDERLINE << "\nList Container Test:" << RESET << std::endl;
    testListContainer();
    return 0;
}