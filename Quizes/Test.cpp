#include "Test.h"

Test::Test()
{
}

Test::Test(std::string name) : name(name)
{
}

Test::~Test()
{
}

Answer Test::createTest()
{
    std::string questionTEXT;
    std::cout << "\n> Input Question: ";
    std::getline(std::cin, questionTEXT);

    std::cout << "\n> Input correct answer -> ";
    std::string ans;
    std::getline(std::cin, ans);

    std::string textUncorrect[3];
    for (int i = 0; i < 3; i++) {
        std::cout << "\n> Input uncorrect answer -> ";
        std::getline(std::cin, textUncorrect[i]);
    }
    return Answer(questionTEXT, ans, textUncorrect);
}