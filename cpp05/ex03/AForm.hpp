#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int signInGrade;
    const int execGrade;

public:
    AForm();
    AForm(const std::string name, const int signInGrade, const int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignInGrade() const;
    int getExecGrade() const;

    void beSigned(Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    virtual void execute(Bureaucrat const& executor) const = 0;
    void checkExecuteRequirements(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif