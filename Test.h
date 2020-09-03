#pragma once
#include "PCH.h"
#include "Answer.h"

class Test : public Answer
{
	std::string name;
public:
	std::vector<Answer> Answers;
	std::vector<Answer>::iterator iter;
	Test();
	Test(std::string name);
	~Test();

	Answer createTest();

	void displayAnswers() { // забей, он неправильно выводит (
		std::for_each(Answers.begin(), Answers.end(), [](Answer & a) {
			a.displayAnswer(); 
		});
		std::cout << "\n> SIZE: " <<Answers.size();
	}
};

