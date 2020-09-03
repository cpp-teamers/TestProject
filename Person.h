#pragma once
#include "PCH.h"
#include "Test.h"
#include "Answer.h"

class Person :  public Test
{
public:
	void createTest();// вывод теста в файл 
	void writeToCatalog(std::string name);
	void readCatalog();
	Test filFile(); // вся логика про прохождение тестов: выбор теста, оценка за тест и т.д.
};

