#include <iostream>
#include <windows.h>
#include <string.h>
#include "./src/queue.hpp"

#define MAXTAM 50

typedef struct Student
{
    int RA;
    char name[30];
} Student;

Queue<Student> *queue = createQ<Student>(MAXTAM);

void register_student();
void serve_student();
void display_queue();
void menu();

using namespace std;

void printStudent(Student s){
    cout << "\nNome: " << s.name
         << "\nRA: " << s.RA << endl;
}


int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    menu();
    return 0;
}

void register_student()
{
    Student s;
    char choose;

    if (!isFull(queue))
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

            enqueue(queue, s);

            cout << "Aluno incluso na fila com sucesso!\n\n";

            cout << "\nDeseja cadastrar outro funcionário?[s/n]  ";
            cin >> choose;
        } while (choose == 's' || choose == 'S' ); 
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
    char choose;

    if (!isEmpty(queue))
    {
        do
        {
            cout << "██████████████████████████████████████████████\n";
            cout << "██             ATENDER ALUNO                ██\n";
            cout << "██████████████████████████████████████████████\n\n";

            dequeue(queue, &s);

            cout << "Aluno atendido com sucesso!\n\n";

            cout << "\nDeseja atender outro funcionário?[s/n]  ";
            cin >> choose;
            if((choose == 's' || choose=='S') && isEmpty(queue)){
                cout << "Desculpe, mas a fila está vazia.";
                break;
            }
        } while (choose == 's' || choose == 'S');
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
    printQueue(queue, printStudent); // n entendi como funciona essa função kkkk // Aqui eu passo um função como parametro
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

        default:
            break;
        }
        system("pause");
    } while (option != 4);
}