#include <iostream>

int main( void ) {
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "brain memory address : " << &brain << std::endl;
    std::cout << "pointer memory address : " << stringPTR << std::endl;
    std::cout << "reference memory address : " << &stringREF<< std::endl;

    std::cout << "brain value : " << brain << std::endl;
    std::cout << "pointer value : " << *stringPTR << std::endl;
    std::cout << "reference value : " << stringREF << std::endl;

    return 0;
}