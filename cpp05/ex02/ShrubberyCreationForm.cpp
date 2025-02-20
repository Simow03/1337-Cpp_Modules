#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreation", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target)
    : AForm("ShrubberyCreation", 145, 137), target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
    : AForm(other) , target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other) {
    if (this != &other) {
        target = other.target;
        AForm::operator=(other);
    }

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const{

    checkExecuteRequirements(executor);

    std::string fileName = target + "_shrubbery";
    std::ofstream targetFile(fileName.c_str());
    if (targetFile.is_open()) {
        targetFile << "        10\n       /  \\\n      5    15\n     / \\   /  \\\n    2   7 12  20" << std::endl;
        targetFile.close();
    }
}