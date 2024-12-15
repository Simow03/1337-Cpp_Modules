#include "Replacer.hpp"

Replacer::Replacer( std::string& inFileInput, std::string& s1Input, std::string& s2Input )
: inFile(inFileInput),
s1(s1Input),
s2(s2Input) {}

bool Replacer::isEmpty( std::string str ) {
    if (str.empty())
        return true;
    return false;
}

bool Replacer::isReadable( std::string inFile ) {
    std::ifstream inFileStream(inFile);
    return (inFileStream.fail());
}
