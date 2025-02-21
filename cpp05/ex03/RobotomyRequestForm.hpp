#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    std::string target;

public: 
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    virtual void execute(Bureaucrat const& executor) const;
};

#endif