#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    std::string target;

public: 
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    virtual void execute(Bureaucrat const& executor) const;
};

#endif