#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

    std::map<std::string, double> dataMap;

    if (ac != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    if (!isValidFileName(av[1])) {
        std::cerr << "Error: filename does not match." << std::endl;
        return 1;
    }
    dataMap = storeDataBase();

    parseInputFile(dataMap);

    return 0;
}