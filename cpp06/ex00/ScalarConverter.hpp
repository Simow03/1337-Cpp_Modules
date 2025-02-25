#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp

#include <iostream>

class ScalarConverter {
private :
    ScalarConverter();
    ScalarConverter(ScalarConverter& other);
    ScalarConverter& operator=(ScalarConverter& other);
    ~ScalarConverter();

    bool isChar(const std::string& input);
    bool isNumber(const std::string& input);

    void convertChar(char c);
    void convertNumber(std::string& input);
public :
    static convert(std::string& input);
};

#endif