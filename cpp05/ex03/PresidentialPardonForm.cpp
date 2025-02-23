#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardon", 145, 137), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target)
    : AForm("PresidentialPardon", 145, 137), target(_target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other)
    : AForm(other) , target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other) {
    if (this != &other) {
        target = other.target;
        AForm::operator=(other);
    }

    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const{

    checkExecuteRequirements(executor);

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}