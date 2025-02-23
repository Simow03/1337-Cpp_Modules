#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main() {
    try {
        std::cout << UNDERLINE << BOLD << "\nTest top form : " << RESET << std::endl;
        
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
        std::cout << UNDERLINE << BOLD << "\nTest regular form : " << RESET << std::endl;
        
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
        std::cout << UNDERLINE << BOLD << "\nTest basic form : " << RESET << std::endl;
        
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