#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("ShrubberyCreation", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target)
    : AForm("ShrubberyCreation", 72, 45), target(_target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other)
    : AForm(other) , target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other) {
    if (this != &other) {
        target = other.target;
        AForm::operator=(other);
    }

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const{

    checkExecuteRequirements(executor);

    std::srand(std::time(0));

    std::cout << "Zzzzz" << std::endl;

    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    }
    else {
        std::cout << "The robotomy of "<< target << " failed." << std::endl;
    }
}