#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        std::cout << "\nTest top form : " << std::endl;
        
        Form top("F_top" ,1 ,1);
        std::cout << top << "\n" << std::endl;

        Bureaucrat high("B_high", 1);
        Bureaucrat medium("B_medium", 80);
        Bureaucrat low("B_low", 150);

        high.signForm(top);
        medium.signForm(top);
        low.signForm(top);
    }
    catch(const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << "\nTest regular form : " << std::endl;
        
        Form regular("F_regular" ,80 ,80);
        std::cout << regular << "\n" << std::endl;

        Bureaucrat high("B_high", 1);
        Bureaucrat medium("B_medium", 80);
        Bureaucrat low("B_low", 150);

        high.signForm(regular);
        medium.signForm(regular);
        low.signForm(regular);
    }
    catch(const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << "\nTest basic form : " << std::endl;
        
        Form basic("F_basic" ,150 ,150);
        std::cout << basic << "\n" << std::endl;

        Bureaucrat high("B_high", 1);
        Bureaucrat medium("B_medium", 80);
        Bureaucrat low("B_low", 150);

        high.signForm(basic);
        medium.signForm(basic);
        low.signForm(basic);
    }
    catch(const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}