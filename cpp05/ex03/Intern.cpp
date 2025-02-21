#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){}

Intern::Intern(Intern& other){
    (void)other;
}
Intern& Intern::operator=(Intern& other){
    if (this != &other){}
    return *this;
}

Intern::~Intern(){}

const char* Intern::FormDoesNotMatchException::what() const throw() {
    return "Form name does not match";
}

AForm *Intern::createRobotomyRequestForm(const std::string& target){
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string& target){
    return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string& target){
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName,const std::string& target) {
    std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm*(Intern::*formCreateFunctions[3])(const std::string& target) = {
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm,
        &Intern::createShrubberyCreationForm
    };

    for (size_t i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*formCreateFunctions[i])(target));
        }
    }

    throw FormDoesNotMatchException();
}