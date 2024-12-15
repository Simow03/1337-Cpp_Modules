#ifndef REPLACER_HPP
# define REPLACER_HPP
#include <iostream>
#include <fstream>

class Replacer {

private:
    std::string inFile;
    std::string outFile;
    std::string s1;
    std::string s2;

public:
    Replacer( std::string& inFileInput, std::string& s1Input, std::string& s2Input );
    bool isEmpty( std::string str );
    bool isReadable( std::string inFile );
};

#endif