#pragma once
#include "PCH.h"
#include "Test.h"
#include "Answer.h"

class Person :  public Test
{
public:
	void createTest();// ����� ����� � ���� 
	void writeToCatalog(std::string name);
	void readCatalog();
	Test filFile(); // ��� ������ ��� ����������� ������: ����� �����, ������ �� ���� � �.�.
};

