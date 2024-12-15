#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Error : Invalid input !" << std::endl;
        std::cerr << "Usage : " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string readed;
    std::ifstream inFile(argv[1]);

    if (inFile.fail()) {
        std::cerr << "Error : Could not open file !" << std::endl;
        return 1;
    }

    while (std::getline(inFile, readed)) {
    }
    
    inFile.close();
}