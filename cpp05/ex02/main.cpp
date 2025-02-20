#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat president("President", 1);
        Bureaucrat manager("Manager", 40);
        Bureaucrat intern("Intern", 140);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n=== Testing Shrubbery Creation ===" << std::endl;
        intern.signForm(shrub);
        intern.executeForm(shrub);

        std::cout << "\n=== Testing Robotomy Request ===" << std::endl;
        manager.signForm(robot);
        manager.executeForm(robot);
        
        std::cout << "\n=== Testing Presidential Pardon ===" << std::endl;
        manager.signForm(pardon);
        president.signForm(pardon);
        president.executeForm(pardon);

        RobotomyRequestForm unsignedRobot("R2D2");
        manager.executeForm(unsignedRobot);

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}