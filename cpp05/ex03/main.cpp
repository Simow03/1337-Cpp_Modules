#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
        delete rrf;
    }
    catch (const Intern::FormDoesNotMatchException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        Intern someRandomIntern;
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Jerry");
    
        delete ppf;
    }
    catch (const Intern::FormDoesNotMatchException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }try {
        Intern someRandomIntern;
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Alfred");
    
        delete scf;
    }
    catch (const Intern::FormDoesNotMatchException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }try {
        Intern someRandomIntern;
        AForm* wnf = someRandomIntern.makeForm("wrong name", "Robin");
    
        delete wnf;
    }
    catch (const Intern::FormDoesNotMatchException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}