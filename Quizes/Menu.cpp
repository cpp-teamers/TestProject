#include "Menu.h"

void Menu::displayMenu()
{
	int choice = 0;

	std::cout << "\n  __________________________________________ ";
	std::cout << "\n | 1. Take the test(yourself or our test)   |";
	std::cout << "\n | 2. Create test                           |";
	std::cout << "\n | 3. Show your marks                       |";
	std::cout << "\n  ``````````````````````````````````````````` ";
	std::cout << "\n --> ";
	std::cin >> choice;
	if (choice < 1 || choice > 4) {
		std::cout << "\n> You input incorrect number! Try again. " << std::endl;
	}
	switch (choice)
	{
	case 1:
		Person::filFile();
		break;
	case 2:
		Person::createTest();
		break;
	case 3:
		break;
	}

}
