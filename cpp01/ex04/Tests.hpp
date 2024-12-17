#ifndef TESTS_HPP
# define TESTS_HPP
#include <iostream>

class Tests
{
private:
    void createTestFile(const std::string& filename, const std::string& content);
    std::string readFileContent(const std::string& filename);
    void cleanupTestFile(const std::string &filename);

public:
    void testBasic(void);
    void testMultiOcc(void);
    void testNoOcc(void);
    void testMultiLine(void);
    void testEmptyStr(void);
    void testEmptyFile(void);
    void runAllTests(void);
};


#endif