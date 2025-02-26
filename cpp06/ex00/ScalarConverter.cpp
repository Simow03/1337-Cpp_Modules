#include "ScalarConverter.hpp"
#include <string>
#include <cctype>
#include <cmath>
#include <climits>
#include <iomanip>

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
    return (input.length() == 1);
}

bool ScalarConverter::isLiteral(const std::string& input) {
    return (input == "nan" || input == "+inf" || input == "-inf"
            || input == "nanf" || input == "+inff" || input == "-inff");
}

bool isInfinite(double val) {
    return (val != 0 && val == val && val * 2 == val);
}

bool isPositiveInfinity(double val) {
    return isInfinite(val) && val > 0;
}

bool isNegativeInfinity(double val) {
    return isInfinite(val) && val < 0;
}

bool ScalarConverter::isNumber(const std::string& input) {
    size_t count = 0;
    bool dot = false;
    bool f = false;
    bool hasDigit = false;

    if (isLiteral(input))
        return true;
    if (input.empty())
        return false;

    if (input[0] == '-' || input[0] == '+')
        count++;

    if (count >= input.length())
        return false;

    for (; count < input.length(); count++)
    {
        if (isdigit(input[count])) {
            hasDigit = true;
            continue;
        }
        else if (input[count] == '.') {
            if (dot)
                return false;
            dot = true;
        }
        else if (input[count] == 'f' && count == input.length() - 1) {
            if (f)
                return false;
            f = true;
        }
        else
            return false;
    }

    return hasDigit;
}

void ScalarConverter::convertChar(const char c) {
    std::cout << "char: ";
    if (isprint(c))
        std::cout << c << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertNumber(const std::string& input) {

    std::string newInput = (input[input.length() - 1] == 'f') ? input.substr(0, input.length() - 1) : input;

    double doubleNumber = strtod(newInput.c_str(), NULL);
    float floatNumber = static_cast<float>(doubleNumber);

    if (doubleNumber >= 0 && doubleNumber <= 127)
    {
        if (isprint(doubleNumber))
            std::cout << "char: " << static_cast<char>(doubleNumber) << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;

    if (doubleNumber <= INT_MAX && doubleNumber >= INT_MIN)
        std::cout << "int: " << static_cast<int>(doubleNumber) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    if (isPositiveInfinity(floatNumber))
        std::cout << "float: +inff" << std::endl;
    else if (isNegativeInfinity(floatNumber))
        std::cout << "float: -inff" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatNumber << "f" << std::endl;

    if (isPositiveInfinity(doubleNumber))
        std::cout << "double: +inf" << std::endl;
    else if (isNegativeInfinity(doubleNumber))
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << doubleNumber << std::endl;
}

void ScalarConverter::convertLiteral(const std::string& input) {
    if (input == "nan" || input == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (input == "+inf" || input == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (input == "-inf" || input == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& input) {
    if(isLiteral(input))
        convertLiteral(input);

    else if (isChar(input))
        convertChar(input[0]);

    else if (isNumber(input))
        convertNumber(input);

    else
        std::cout << "Error: Invalid Input" << std ::endl;
}