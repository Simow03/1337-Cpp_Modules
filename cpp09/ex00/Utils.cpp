#include "BitcoinExchange.hpp"

bool containsMultiplePipe(std::string input) {

    int count = 0;

    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == '|')
            count++;
    }

    return (count > 1) ? true : false;
}

std::string readFromFile(std::string filename) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    std::stringstream fileContentStream;

    fileContentStream << inputFile.rdbuf();

    return fileContentStream.str();
}

std::string trimWhitespace(const std::string& str) {
    if(str.empty())
        return str;
    
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";

    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

int countSegments(const std::string& str, char delimiter) {
    int count = 0;

    size_t start = 0;
    size_t end = 0;

    while ((end = str.find(delimiter, start)) != std::string::npos) {
        if(end != start)
            count++;
        
        start = end + 1;
    }

    if (start < str.length())
        count++;
    
    return count;
}

std::string* splitString(std::string fileContent, char delimiter) {
    int segmentCount = countSegments(fileContent, delimiter);


    std::string* result = new std::string[segmentCount + 1];
    
    char countStr[20];
    sprintf(countStr, "%d", segmentCount);
    result[0] = countStr;

    size_t i = 1;
    size_t start = 0;
    size_t end = 0;

    while((end = fileContent.find(delimiter, start)) != std::string::npos) {
        if (end != start)
            result[i++] = fileContent.substr(start, end - start);

        start = end + 1;
    }

    if (start < fileContent.length())
        result[i] = fileContent.substr(start);

    return result;
}

void freeSplitString(std::string* array) {
    if (array != NULL)
        delete[] array;
}