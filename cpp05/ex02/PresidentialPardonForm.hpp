#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string target;

public: 
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    virtual void execute(Bureaucrat const& executor) const;
};

#endif