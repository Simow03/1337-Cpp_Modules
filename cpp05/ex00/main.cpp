#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << "\nTest insertion : " << std::endl;
        Bureaucrat testCout("testCoutName", 100);
        std::cout << testCout << std::endl;

        std::cout << "\nIncrementing grade : " << std::endl;
        testCout.incrementGrade();
        std::cout << testCout << std::endl;
        
        std::cout << "\nTest grade too high : " << std::endl;
        Bureaucrat TooHigh("TooHigh", 0);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "\nTest grade too low : " << std::endl;
        Bureaucrat TooLow("TooLow", 151);
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat topGrade("TopGrade", 10);
        std::cout << "\nTest increment into max grade : " << std::endl;
        for (size_t i = 0; i < 10; i++) {
            topGrade.incrementGrade();
        }
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}