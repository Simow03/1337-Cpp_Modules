#include "BitcoinExchange.hpp"

bool isValidFileName(std::string filename) {
    return filename == "input.txt" ? true : false;
}

bool validateDate(std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (size_t i = 0; i < yearStr.length(); i++)
        if (!isdigit(yearStr[i]))
            return false;
    for (size_t i = 0; i < monthStr.length(); i++)
        if (!isdigit(monthStr[i]))
            return false;
    for (size_t i = 0; i < dayStr.length(); i++)
        if (!isdigit(dayStr[i]))
            return false;
    
    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    }
    else if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeapYear ? 29 : 28))
            return false;
    }

    return true;
}

bool validateValue(std::string& value) {

    int startPos = (value[0] == '-' ? 1 : 0);

    if (startPos != 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }

    bool isNumeric = true;
    bool isFloat = false;

    for (size_t i = startPos; i < value.length(); i++) {
        if (value[i] == '.' && !isFloat)
            isFloat = true;
        else if (!isdigit(value[i])) {
            isNumeric = false;
            break;
        }
    }
    if (!isNumeric)
        return false;

    double doubleValue = std::strtod(value.c_str(), NULL);

    if (doubleValue > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

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

void parseInputFile(std::map<std::string, double> dataMap) {

    (void)dataMap;
    std::string fileContent = readFromFile("input.txt");

    if(fileContent.empty()) {
        std::cerr << "Error: file is empty." << std::endl;
        exit(1);
    }

    std::string* contentArray = splitString(fileContent, '\n');

    if (contentArray[1] != "date | value") {
        std::cerr << "Error: invalid header format." << std::endl;
        freeSplitString(contentArray);
        exit(1);
    }
    size_t count = atoi(contentArray[0].c_str());
    for (size_t i = 2; i <= count; i++) {
        std::string* dateValueArray = splitString(contentArray[i], '|');
        size_t tokens = atoi(dateValueArray[0].c_str());
        if (tokens != 2) {
            std::cout << "Error: bad input => " << contentArray[i] << std::endl;
            freeSplitString(dateValueArray);
            continue;
        }

        std::string dateStr = trimWhitespace(dateValueArray[1]);
        std::string valueStr = trimWhitespace(dateValueArray[2]);

        if (!validateDate(dateStr)) {
            std::cout << "Error: bad date format => " << dateStr << std::endl;
            freeSplitString(dateValueArray);
            continue;
        }
        if (!validateValue(valueStr)) {
            freeSplitString(dateValueArray);
            continue;
        }

        double value = std::strtod(valueStr.c_str(), NULL);

        std::map<std::string, double>::iterator it = dataMap.lower_bound(dateStr);

        if (it->first != dateStr)
            it--;

        std::cout << dateStr << " => " << value << " = " << it->second * value << std::endl;

        freeSplitString(dateValueArray);
    }

    freeSplitString(contentArray);
}