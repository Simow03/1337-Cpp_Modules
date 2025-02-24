#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp

#include <iostream>

class ScalarConverter {
private :
    ScalarConverter();
    ScalarConverter(ScalarConverter& other);
    ScalarConverter& operator=(ScalarConverter& other);
    ~ScalarConverter();
public :
    static convert(std::string& input);
};

#endif