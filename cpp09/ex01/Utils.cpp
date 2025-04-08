#include "RPN.hpp"

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
    
    std::ostringstream oss;
    oss << segmentCount;
    result[0] = oss.str();

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