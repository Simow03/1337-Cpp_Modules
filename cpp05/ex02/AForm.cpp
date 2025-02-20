#include "AForm.hpp"

AForm::AForm()
    : name("Default"),
    isSigned(false),
    signInGrade(80),
    execGrade(80) {}

AForm::AForm(const std::string _name, const int _signInGrade, const int _execGrade)
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

AForm::AForm(const AForm& other)
    : name(other.name),
    isSigned(other.isSigned),
    signInGrade(other.signInGrade),
    execGrade(other.execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }

    return *this;
}

const std::string& AForm::getName() const {
    return name;
}
bool AForm::getIsSigned() const {
    return isSigned;
}
int AForm::getSignInGrade() const {
    return signInGrade;
}
int AForm::getExecGrade() const {
    return execGrade;
}

AForm::~AForm() {}

void AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= getSignInGrade())
        isSigned = true;
    else { 
        isSigned = false;
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName()
    << ", sign in grade " << form.getSignInGrade()
    << ", execution grade " << form.getExecGrade()
    << (form.getIsSigned() ? ", Signed" : ", Not signed");

    return os;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high, Maximun grade : 1";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low, Minimun grade is : 150";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form needs to be signed before execution";
}

void AForm::checkExecuteRequirements(const Bureaucrat& executor) const {
    if(!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
}