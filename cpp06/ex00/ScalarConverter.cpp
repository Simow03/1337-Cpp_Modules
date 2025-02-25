#include "ScalarConverter.hpp"
#include <string>
#include <cctype>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) {
    (void)other;

    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& input) {
    return (input.length() == 1)
}

bool isLiteral(cont std::string& input) {
    return (input == "nan" || input == "+inf" || input == "-inf"
            || input == "nanf" || input == "+inff" || input == "-inff")
}

bool ScalarConverter::isNumber(const std::string& input) {
    int count = 0;
    bool dot = false;
    bool f = false;

    if (isLiteral(input))
        return true;
    if (input.empty())
        return false;

    if (input[0] == '-' || input == '+')
        count++;

    if (count >= input.length())
        return false;

    for (; count < input.length(); count++)
    {
        if (isdigit(input[i]))
            continue;
        else if (input[i] == '.') {
            if (dot)
                return false;
            dot = true;
        }
        else if (input[i] == 'f' && i == input.length() - 1) {
            if (f)
                return false;
            f = true;
        }
        else
            return false;
    }

    bool hasDigit = false;
    for (size_t i = count; i < input.length(); i++) {
        if (isdigit(input[i])) {
            hasDigit = true;
            break;
        }
    }

    return hasDigit;
}

ScalarConverter::convertChar(char c) {
    std::cout << "char: ";
    if (isprint(c))
        std::cout << c << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

ScalarConverter::convert(std::string& input) {
    if (isChar(input))
        convertChar(input[0]);
    
    else if (isNumber(input))
        convertNumber(input);
}