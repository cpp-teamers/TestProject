#pragma once
#include "PCH.h"
#include "Test.h"
#include "Answer.h"

class Person :  public Test
{
public:
	void createTest();// ����� ����� � ���� 
	void writeToCatalog(std::string name); // ���������� ����� txt
	void readCatalog(); // ���������� �����
	void readResult(); // ������ ���������� � ����
	void readMarks(int grades); // ������ ������ � ����
	void writeMarks(); // ���������� ������ � �������

	Test filFile(); // ��� ������ ��� ����������� ������: ����� �����, ������ �� ���� � �.�.
};

