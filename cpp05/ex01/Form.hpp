#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool isSigned;
    const int signInGrade;
    const int execGrade;

public:
    Form();
    Form(const std::string name, const int signInGrade, const int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignInGrade() const;
    int getExecGrade() const;

    void beSigned(Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade too high, Maximun grade : 1";
        }
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade too low, Minimun grade is : 150";
        }
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif