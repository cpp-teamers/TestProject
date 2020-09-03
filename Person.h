#pragma once
#include "PCH.h"
#include "Test.h"
#include "Answer.h"

class Person :  public Test
{
public:
	void createTest();// вывод теста в файл 
	void writeToCatalog(std::string name); // Запоминает имена txt
	void readCatalog(); // считывание теста
	void readResult(); // запись результата в файл
	void readMarks(int grades); // запись оценок в файл
	void writeMarks(); // считывание оценок в консоль

	Test filFile(); // вся логика про прохождение тестов: выбор теста, оценка за тест и т.д.
};

