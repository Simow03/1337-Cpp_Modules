#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(Intern& other);
    Intern& operator=(Intern& other);
    ~Intern();

    AForm *makeForm(const std::string& formName,const std::string& target);

    AForm *createRobotomyRequestForm(const std::string& target);
    AForm *createPresidentialPardonForm(const std::string& target);
    AForm *createShrubberyCreationForm(const std::string& target);

    class FormDoesNotMatchException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

#endif