#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>

bool isValidFileName(std::string filename);
std::map<std::string, double> storeDataBase(void);
void parseInputFile(std::map<std::string, double> dataMap);
std::string readFromFile(std::string filename);
std::string trimWhitespace(const std::string& str);
int countSegments(const std::string& str, char delimiter);
std::string* splitString(std::string fileContent, char delimiter);
void freeSplitString(std::string* array);
bool containsMultiplePipe(std::string input);

#endif