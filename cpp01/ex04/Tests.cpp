#include "Tests.hpp"
#include "Replacer.hpp"
#include <fstream>
#include <cstdio>

void Tests::createTestFile(const std::string &filename, const std::string &content)
{
    std::ofstream testFile(filename);
    if (!testFile)
    {
        std::cerr << "Error: Failed to create output file !" << std::endl;
        exit(1);
    }
    testFile << content;
    testFile.close();
}

std::string Tests::readFileContent(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Failed to open file !" << std::endl;
        exit(1);
    }
    std::string buffer;
    std::string line;

    while (getline(file, line))
        buffer += line + '\n';
    file.close();
    return buffer;
}

void Tests::cleanupTestFile(const std::string &filename)
{
    std::remove(filename.c_str());
    std::remove((filename + ".replace").c_str());
}

void Tests::testBasic()
{
    std::string testFilename = "test_basic.txt";
    createTestFile(testFilename, "hello world, hello universe");

    Replacer replacer(testFilename, "hello", "hi");
    replacer.replace();

    std::string expected = "hi world, hi universe\n";
    std::string actual = readFileContent(testFilename + ".replace");

    if (actual == expected)
    {
        std::cout << "Test Passed !" << std::endl;
    }
    else
    {
        std::cout << "Test Failed .." << std::endl;
    }

    cleanupTestFile(testFilename);
}

void Tests::testMultiOcc()
{
    std::string testFilename = "test_multiple_occ.txt";
    createTestFile(testFilename, "cat cat cat");

    Replacer replacer(testFilename, "cat", "dog");

    replacer.replace();

    std::string expected = "dog dog dog\n";
    std::string actual = readFileContent(testFilename + ".replace");

    if (actual == expected)
    {
        std::cout << "Test Passed !" << std::endl;
    }
    else
    {
        std::cout << "Test Failed .." << std::endl;
    }

    cleanupTestFile(testFilename);
}

void Tests::testNoOcc()
{
    std::string testFilename = "test_no_occ.txt";
    std::string originalContent = "No replacement needed";
    createTestFile(testFilename, originalContent);

    Replacer replacer(testFilename, "xyz", "abc");
    replacer.replace();

    std::string expected = originalContent + "\n";
    std::string actual = readFileContent(testFilename + ".replace");

    if (actual == expected)
    {
        std::cout << "Test Passed !" << std::endl;
    }
    else
    {
        std::cout << "Test Failed .." << std::endl;
    }

    cleanupTestFile(testFilename);
}

void Tests::testMultiLine()
{
    std::string testFilename = "test_multiline.txt";
    createTestFile(testFilename, "first line hello\nsecond line hello");

    Replacer replacer(testFilename, "hello", "hi");
    replacer.replace();

    std::string expected = "first line hi\nsecond line hi\n";
    std::string actual = readFileContent(testFilename + ".replace");

    if (actual == expected)
    {
        std::cout << "Test Passed !" << std::endl;
    }
    else
    {
        std::cout << "Test Failed .." << std::endl;
    }

    cleanupTestFile(testFilename);
}

void Tests::testEmptyStr()
{
    std::string testFilename = "test_empty_string.txt";
    createTestFile(testFilename, "this string should be empty !");

    Replacer replacer(testFilename, "", "hi");
    replacer.replace();

    std::string expected = "this string should be empty !";
    std::string actual = readFileContent(testFilename + ".replace");

    if (actual == expected)
    {
        std::cout << "Test Passed !" << std::endl;
    }
    else
    {
        std::cout << "Test Failed .." << std::endl;
    }

    cleanupTestFile(testFilename);
}

void Tests::testEmptyFile()
{
    std::string testFilename = "test_empty_lines.txt";
    createTestFile(testFilename, "");

    Replacer replacer(testFilename, "no", "yes");
    replacer.replace();

    std::string expected = "";
    std::string actual = readFileContent(testFilename + ".replace");

    if (actual == expected)
    {
        std::cout << "Test Passed !" << std::endl;
    }
    else
    {
        std::cout << "Test Failed .." << std::endl;
    }

    cleanupTestFile(testFilename);
}

void Tests::runAllTests()
{
    testBasic();
    testMultiOcc();
    testNoOcc();
    testMultiLine();
    testEmptyStr();
    testEmptyFile();
}
