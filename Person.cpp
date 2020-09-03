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
        system("cls");
        t.Answers.push_back(t.createTest());
        // ������ ����� ���� ��� ���
        std::cout << "\n> Will you continue make the test? (1-yes/0-no)  -> ";
        std::cin >> cont;
    } while (cont == 1);

    // ��� ��������������� ������ � ����
    std::for_each(t.Answers.begin(), t.Answers.end(), [&Fout](Answer& a) {
        Fout << a.question << std::endl;
        Fout << "." << a.text1 << std::endl;
        for (int i = 0; i < 3; i++) {
            Fout << "-" << a.textUncorrect[i] << std::endl;
        }
        });
    Fout.close();
}

void Person::writeToCatalog(std::string name) // ������ � �������
{
    std::ofstream fout;
    fout.open("Catalog.txt", std::ios_base::app);
    fout << name << std::endl;
    fout.close();
}

void Person::readCatalog() // ������ � ��������
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

void Person::readResult()
{
    std::cout << "\n> Your results:" << std::endl;

    std::string question;
    std::string answer;

    std::ifstream fin;
    fin.open("Results.txt");
    while (!fin.eof())
    {
        question = "";
        answer = "";
        std::getline(fin, question);
        std::getline(fin, answer);
        std::cout << question << std::endl;
        std::cout << answer << std::endl;
    }
    fin.close();
}

void Person::readMarks(int grades)
{
    std::ofstream fout;
    fout.open("Marks.txt", std::ios_base::app);
    fout << grades << std::endl;
    fout.close();
}

void Person::writeMarks()
{
    std::ifstream fin;
    fin.open("Marks.txt");

    std::string mark;
    double S = 0;
    int counter = 0;
    int num;

    std::cout << "\n> Your grade -> ";
    while (!fin.eof())
    {
        std::getline(fin, mark);
        if (mark.empty()) {
            break;
        }
        std::cout << mark << " ";
        //
        num = std::stoi(mark);
        S = S + num;
        counter++;
    }
    S = S / counter;
    std::cout << "\n> Your average mark -> " << std::setprecision(2) << S;
    fin.close();
}

Test Person::filFile()
{
    // ������ �����
    readCatalog();
    std::cout << "\n> Write the test, which you want to pass(all characters and ducks) ->";
    std::string txt;
    std::cin >> txt;

    std::ifstream fin; // ��� ������ ����� � �������
    std::ofstream fout; // ��� ������ ������(�����������) � ��������� ����

    fin.open(txt);
    fout.open("Results.txt");

    // ����������, ������� ������������ ��� �������� ������� ������ Answer
    char cor;
    std::string question;
    std::string correct;
    std::string uncorrect[3];
    short int counter;
    // ��������� ��� ����� � ���������
    short int userAnswer = 0;
    int grade = 0;
    short int i = 0;
    int c = 0;
    //
    Test t(txt);

    system("cls"); // ������� ������, ����� ������� ������ ���� � �������, ������� ��� ��������)

    if (fin.is_open())
    {
        while (!fin.eof())
        {
            i++;
            system("cls");
            std::getline(fin, question);

            if (question.empty()) { break; }

            std::cout << "\n " << i << ". " << question << std::endl;
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
        }

        fout << "\n  _______________________";
        fout << "\n | Your grade: " << grade << " points. |";
        fout << "\n  ```````````````````````";
        fin.close();
        fout.close();

        readResult(); // ����� �� ����� ����������
        readMarks(grade); // ���������� ������ � ��������� ����
        return t;
    }
    else {
        std::cout << "\n> That test wasn`t found in folder!!!";
    }
}
