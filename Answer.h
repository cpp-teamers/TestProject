#pragma once
#include "PCH.h"

class Answer
{
public:
	std::string question; // ����� �������
	std::string text1; // ����� ����������� �����a
	std::string textUncorrect[3]; // ����� �����, ������� ������������
	Answer();
	Answer(std::string question, std::string text1, std::string textUncorrect[3]);
	void displayAnswer();
	~Answer();
};

