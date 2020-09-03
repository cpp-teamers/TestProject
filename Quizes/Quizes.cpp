#include "PCH.h"
#include "Menu.h"

int main()
{
    char choice = 'n';
    Menu m;
    do {
        system("cls");
        m.displayMenu(); // основная логика
        std::cout << "\n> Continue? (y/n) -> ";
        std::cin >> choice;
    } while (choice == 'y');

    // Finish ->
    std::cout << "\n> Programm finished (0_0) " << std::endl;
}
