#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp

#include <iostream>
#include <exception>

class ScalarConverter {
private :
    ScalarConverter();
    ScalarConverter(ScalarConverter& other);
    ScalarConverter& operator=(ScalarConverter& other);
    ~ScalarConverter();

    static bool isChar(const std::string& input);
    static bool isNumber(const std::string& input);
    static bool isLiteral(const std::string& input); 

    static void convertChar(const char c);
    static void convertNumber(const std::string& input);
    static void convertLiteral(const std::string& input);

public :
    static void convert(const std::string& input);

};

#endif