#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {}

Base* Base::generate(void){

    static bool flag = true;
    if (flag) {
        std::srand(time(0));
        flag = false;
    }

    int randNumber = std::rand() % 3;

    switch (randNumber)
    {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    default:
        return NULL;
    }
}

void Base::identify(Base* p){
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Not Base instance!" << std::endl;
}

void Base::identify(Base& p){
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(std::exception&) {}
    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(std::exception&) {}
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(std::exception& e) {
        std::cout << "Exception Caught: " << e.what() << std::endl;
    }
}
