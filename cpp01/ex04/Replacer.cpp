#include "Replacer.hpp"

Replacer::Replacer( const std::string& inFileInput, const std::string& s1Input, const std::string& s2Input )
: inFileName(inFileInput),
outFileName(inFileInput + ".replace"),
s1(s1Input),
s2(s2Input) {}

bool Replacer::isReadable( std::string& inFile ) {
    std::ifstream inFileStream(inFile);
    return (inFileStream.good());
}

void Replacer::replace() {
    if (s1.empty()) {
        std::cerr << "Error: Search string is empty !" << std::endl;
        return ;
    }
    if (!isReadable(inFileName)) {
        std::cerr << "Error : Could not open file !" << std::endl;
        return ;
    }

    std::ifstream inFile(inFileName);
    if (!inFile) {
        std::cerr << "Error: Failed to open input file !" << std::endl;
        return ;
    }
    std::ofstream outFile(outFileName);
    if (!outFile) {
        std::cerr << "Error: Failed to create output file !" << std::endl;
        inFile.close();
        return ;
    }

    std::string readed;

    while (std::getline(inFile, readed)) {
        size_t pos = 0;
        while (true) {
            pos = readed.find(s1, pos);
            if (pos == std::string::npos)
                break ;
            readed.erase(pos, s1.length());
            readed.insert(pos, s2);
            pos += s2.length();
        }

        outFile << readed << std::endl;
    }

    inFile.close();
    outFile.close();
}