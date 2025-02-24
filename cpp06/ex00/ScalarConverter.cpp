#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) {
    (void)other;

    return *this;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::convert(std::string& input) {
}