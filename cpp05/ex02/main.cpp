#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

int main() {
    try {
        Bureaucrat president("President", 1);
        Bureaucrat manager("Manager", 40);
        Bureaucrat intern("Intern", 140);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur");

        std::cout << UNDERLINE << BOLD << "\nTest Shrubbery Creation :" << RESET << std::endl;
        intern.signForm(shrub);
        intern.executeForm(shrub);

        std::cout << UNDERLINE << BOLD << "\nTest Robotomy Request :" << RESET << std::endl;
        manager.signForm(robot);
        manager.executeForm(robot);
        
        RobotomyRequestForm unsignedRobot("Robot");
        manager.executeForm(unsignedRobot);
    
        std::cout << UNDERLINE << BOLD << "\nTest Presidential Pardon :" << RESET << std::endl;
        manager.signForm(pardon);
        president.signForm(pardon);
        president.executeForm(pardon);
        intern.executeForm(pardon);


    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}