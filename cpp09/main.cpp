#include "BitcoinExchange.hpp"

std::map<std::string, double> storeDataBase() {

    std::map<std::string, double> dataMap;

    std::string fileContent = readFromFile("data.csv");

    std::string* contentArray = splitString(fileContent, '\n');

    size_t count = atoi(contentArray[0].c_str());

    for(size_t i = 2; i <= count; i++) {
        std::string* dateRateArray = splitString(contentArray[i], ',');

        dataMap[dateRateArray[1]] = std::strtod(dateRateArray[2].c_str(), NULL);

        freeSplitString(dateRateArray);
    }
    freeSplitString(contentArray);

    return dataMap;
}

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
    for (std::map<std::string, double>::iterator it = dataMap.begin(); it != dataMap.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    }
    // parseInputFile(dataMap);

    return 0;
}