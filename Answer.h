#pragma once
#include "PCH.h"

class Answer
{
public:
	std::string question; // текст вопроса
	std::string text1; // текст правильного ответa
	std::string textUncorrect[3]; // текст ответ, которые неправильные
	Answer();
	Answer(std::string question, std::string text1, std::string textUncorrect[3]);
	void displayAnswer();
	~Answer();
};

