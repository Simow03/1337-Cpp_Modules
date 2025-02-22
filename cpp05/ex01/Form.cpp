#include "Form.hpp"

Form::Form()
    : name("Default"),
    isSigned(false),
    signInGrade(80),
    execGrade(80) {}

Form::Form(const std::string _name, const int _signInGrade, const int _execGrade)
    : name(_name),
    isSigned(false),
    signInGrade(_signInGrade),
    execGrade(_execGrade)
    {
        if (_signInGrade < 1 || _execGrade < 1)
            throw GradeTooHighException();
        if (_signInGrade > 150 || _execGrade > 150)
            throw GradeTooLowException();
    }

Form::Form(const Form& other)
    : name(other.name),
    isSigned(other.isSigned),
    signInGrade(other.signInGrade),
    execGrade(other.execGrade) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }

    return *this;
}

const std::string& Form::getName() const {
    return name;
}
bool Form::getIsSigned() const {
    return isSigned;
}
int Form::getSignInGrade() const {
    return signInGrade;
}
int Form::getExecGrade() const {
    return execGrade;
}

Form::~Form() {}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= getSignInGrade())
        isSigned = true;
    else { 
        isSigned = false;
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName()
    << ", sign in grade " << form.getSignInGrade()
    << ", execution grade " << form.getExecGrade()
    << (form.getIsSigned() ? ", Signed" : ", Not signed");

    return os;
}

virtual const char* GradeTooHighException::what() const throw() {
    return "Grade too high, Maximun grade : 1";
}

virtual const char* GradeTooLowException::what() const throw() {
    return "Grade too low, Minimun grade is : 150";
}
