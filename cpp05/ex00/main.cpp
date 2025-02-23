#include "Bureaucrat.hpp"

const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main() {
    try {
        std::cout << UNDERLINE << BOLD << "\nTest insertion :" << RESET << std::endl;
        Bureaucrat testCout("testCoutName", 100);
        std::cout << testCout << std::endl;

        std::cout << UNDERLINE << BOLD << "\nIncrementing grade :" << RESET << std::endl;
        testCout.incrementGrade();
        std::cout << testCout << std::endl;
        
        std::cout << UNDERLINE << BOLD << "\nTest grade too high :" << RESET << std::endl;
        Bureaucrat TooHigh("TooHigh", 0);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        std::cout << UNDERLINE << BOLD << "\nTest grade too low :" << RESET << std::endl;
        Bureaucrat TooLow("TooLow", 151);
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat topGrade("TopGrade", 10);
        std::cout << UNDERLINE << BOLD << "\nTest increment into max grade : " << RESET << std::endl;
        for (size_t i = 0; i < 10; i++) {
            topGrade.incrementGrade();
        }
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}