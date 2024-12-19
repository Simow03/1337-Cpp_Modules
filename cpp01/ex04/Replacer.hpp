#ifndef REPLACER_HPP
# define REPLACER_HPP
#include <iostream>
#include <fstream>

class Replacer {

private:
    std::string inFileName;
    std::string outFileName;
    std::string s1;
    std::string s2;

public:
    Replacer( const std::string& inFileInput, const std::string& s1Input, const std::string& s2Input );
    void replace( void );
};

#endif