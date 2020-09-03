#include "Answer.h"

Answer::Answer() : text1("undef.text1"), question("undef.question")
{
}

Answer::Answer(std::string question, std::string text1, std::string textUncorrect[3]) : question(question), text1(text1)
{
	for (int i = 0; i < 3; i++)
	{
		this->textUncorrect[i] = textUncorrect[i];
	}
}

void Answer::displayAnswer() // проверка
{
	std::cout << "\n> Question: " << question;
	std::cout << "\n>  Text " << text1;
	for (int i = 0; i < 3; i++) {
		std::cout << "\n> Uncorrect: " << textUncorrect[i];
	}
}

Answer::~Answer()
{
}
