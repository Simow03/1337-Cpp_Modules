#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(80) {};

Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : name(_name) {
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
    grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if(this != &other) {
        grade = other.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){};

const std::string& Bureaucrat::getName() const{
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

void Bureaucrat::incrementGrade() {
    grade--;
    if (grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
    grade++;
    if (grade > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high, Maximun grade : 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low, Minimun grade is : 150";
}