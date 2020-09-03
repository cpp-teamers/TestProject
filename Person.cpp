#include "Person.h"

void Person::createTest()
{
    std::cout << "\n> Input name of Test ->";
    std::string T;
    bool cont = true;

    std::cin >> T;
    Test t(T);

    T.append(".txt");
    writeToCatalog(T);
    std::ofstream Fout;
    Fout.open(T);
    do {
        t.Answers.push_back(t.createTest());
        // Дальше пишем тест или нет
        std::cout << "\n> Will you continue make the test? (1-yes/0-no)  -> ";
        std::cin >> cont;
    } while (cont == 1);

    // Уже непосредственно запись в файл
    std::for_each(t.Answers.begin(), t.Answers.end(), [&Fout](Answer& a) {
        Fout << a.question << std::endl;
        Fout << "1 " << a.text1 << std::endl;
        for (int i = 0; i < 3; i++) {
            Fout << i + 2 << " " << a.textUncorrect[i] << std::endl;
        }
        });
    Fout.close();
}

void Person::writeToCatalog(std::string name) // Запись в каталог
{
    std::ofstream fout;
    fout.open("Catalog.txt", std::ios_base::app);
    fout << name << std::endl;
    fout.close();
}

void Person::readCatalog() // чтение з каталога
{
    std::cout << "\n> Catalog of tests:" << std::endl;
    std::string name;
    std::ifstream fin;
    fin.open("Catalog.txt");
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            name = "";
            fin >> name;
            std::cout << name << " ";
        }
    }
    fin.close();
}

Test Person::filFile()
{
    // Чтение файла - работает как пушечка)
    readCatalog();
    std::cout << "\n> Write the test, which you want to pass(all characters and ducks) ->";
    std::string txt;
    std::cin >> txt;

    std::ifstream fin; // Для чтения теста в консоль
    std::ofstream fout; // для вывода данных(результатов) в отдельный файл

    fin.open(txt);
    fout.open("Results.txt");

    // Переменные, которые используются для создание объекта класса Answer
    char cor;
    std::string question;
    std::string correct;
    std::string uncorrect[3];
    short int counter;
    // Переменые для ввода и сравнения
    short int userAnswer = 0;
    int grade = 0;
    short int i = 0;
    int c = 0;
    //
    Test t(txt);

    system("cls"); // Очистка экрана, чтобы остался только тест и человек, который его проходит)

    if (fin.is_open())
    {
        while (!fin.eof())
        {
            std::getline(fin, question);
            std::cout << "\n>" << question << std::endl;
            counter = 0;
            for (int i = 0; i < 4; i++)
            {
                fin >> cor;
                if (cor == '.')
                {
                    std::getline(fin, correct);
                    std::cout << "\n " << i + 1 << " " << correct;
                    c = i + 1;
                }
                else
                {
                    std::getline(fin, uncorrect[counter]);
                    std::cout << "\n " << i + 1 << " " << uncorrect[counter];
                    counter++;
                }
            }
            // Input data
            std::cout << "\n --> ";
            std::cin >> userAnswer;
            t.Answers.push_back(Answer(question, correct, uncorrect));

            fout << question << std::endl;
            if (userAnswer == c) {
                fout << "Good! Correct answer." << std::endl;
                grade++;
            }
            else {
                fout << "Incorrect answer." << std::endl;
            }
            // 
            i++;
        }
        fout << "\n  _______________________";
        fout << "\n | Your grade: " << grade << " points. |";
        fout << "\n  ```````````````````````";
        fin.close();
        fout.close();
        return t;
    }
    else {
        std::cout << "\n> That test wasn`t found in folder!!!";
    }
}
