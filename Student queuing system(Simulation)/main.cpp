#include <iostream>
#include <windows.h>
#include "./src/queue.hpp"

#define MAXTAM 50

typedef struct Student
{
    int RA;
    char name[30];
} Student;

typedef struct TQueue
{
    Queue<Student> *queue = createQ<Student>(MAXTAM);
    int amount = 0;
} TQueue;

void register_student();
void serve_student();
void display_queue();
void menu();

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    menu();
    system("pause");
    return 0;
}

void register_student()
{
    Student s;
    TQueue q;
    char choose;

    if (!isFull(q.queue))
    {
        do
        {
            cout << "██████████████████████████████████████████████\n";
            cout << "██             INCLUSÃO DE ALUNO            ██\n";
            cout << "██████████████████████████████████████████████\n\n";

            cin.ignore();
            cout << "Nome do aluno: ";
            gets(s.name);
            cout << "Número do RA: ";
            cin >> s.RA;

            enqueue(q.queue, s);

            q.amount++;

            cout << "Aluno incluso na fila com sucesso!\n\n";

            cout << "\nDeseja cadastrar outro funcionário?[s/n]  ";
            cin >> choose;
        } while (choose == 's' || choose == 'S' || choose == 'sim' || choose == 'Sim');
    }
    else
    {
        cout << "A fila já está cheia, impossível adicionar mais alunos.";
    }
    cout << "\nVoltando ao menu pricipal, aguarde";
    for (int i = 0; i < 7; i++)
    {
        Sleep(300);
        cout << ". ";
    }
    system("cls");
}

void serve_student()
{
    Student s;
    TQueue q;
    char choose;

    if (!isEmpty(q.queue))
    {
        do
        {
            cout << "██████████████████████████████████████████████\n";
            cout << "██             ATENDER ALUNO                ██\n";
            cout << "██████████████████████████████████████████████\n\n";

            dequeue(q.queue, s); // n entendi como funciona essa função kkkk

            q.amount--;

            cout << "Aluno atendido com sucesso!\n\n";

            cout << "\nDeseja atender outro funcionário?[s/n]  ";
            cin >> choose;
        } while (choose == 's' || choose == 'S' || choose == 'sim' || choose == 'Sim');
    }
    else
    {
        cout << "A fila está vazia, impossível atender mais alunos.";
    }

    cout << "\nVoltando ao menu pricipal, aguarde";
    for (int i = 0; i < 7; i++)
    {
        Sleep(300);
        cout << ". ";
    }
    system("cls");
}

void display_queue()
{
    TQueue q;
    Student s;

    while (!isEmpty(q.queue))
    {
        printQueue(q.queue, s); // n entendi como funciona essa função kkkk
    }
}

void menu()
{
    int option;
    do
    {
        system("cls");

        cout << " \n    ████████████████████████████████████████████████████████████\n";
        cout << "                             FILA DE ESTUDANTES                    ";
        cout << " \n    ██                                                        ██";
        cout << " \n    ████████████████████████████████████████████████████████████\n";
        cout << " \n    ██             1 - Incluir um novo aluno                  ██";
        cout << " \n    ██             2 - Atender aluno                          ██";
        cout << " \n    ██             3 - Exibir fila                            ██";
        cout << " \n    ██             4 - Sair                                   ██";
        cout << " \n    ████████████████████████████████████████████████████████████\n";

        system("cls");

        while ((cout << "\n Digite o numero referente a sua opçao: ") && !(cin >> option))
        {
            cout << "  \n        Digite uma opção válida.";
            cin.clear();
            cin.ignore();
            Sleep(1000);
            system("cls");
        }
        switch (option)
        {
        case 1:
            register_student();
            break;

        case 2:
            serve_student();
            break;

        case 3:
            display_queue();
            break;

        case 4:
            system("pause");
            break;

        default:
            system("pause");
            break;
        }
        system("pause");
    } while (option != 4);
}