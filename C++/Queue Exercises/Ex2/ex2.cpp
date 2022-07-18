/*
Pt-BR - Utilizando as TADs implementadas para Filas, acrescidas das fun¸c˜oes que julgar pertinente, 
elabore um programa que divida uma determinada Fila de n Clientes (n ≤ MAXTAM) em duas filas.
Considerando a estrutura da fila inicial e os dados atribu´ıdos (manualmente ou por sorteio), mova
os(as) clientes gestantes e maiores de 60 anos para a nova fila chamada Fila Prioritaria. Mostre
as duas filas.

Eng - Using the TADs implemented for Queues, plus the functions you deem pertinent, 
Write a program that divides a given Queue of n Clients (n ≤ MAXTAM) into two queues.
Given the initial queue structure and the data assigned (manually or by lot), move
the customers who are pregnant and over 60 years old to the new queue called Priority Queue. Show
the two queues.
*/

#include <iostream>
#include <windows.h>
#include <stack>
#include <vector>
#include <queue>
#define MAXTAM 20

using namespace std;

typedef struct
{
    int age;
    bool pregnant;
} Client;

typedef struct
{
    queue<Client> queue1[MAXTAM];
    int start, end;
    int amount;
} TQueue;

queue<Client> priorityQueue[MAXTAM];
queue<Client> restQueue[MAXTAM];

void startQueue(TQueue *f);
void signUp(int size);
void insertQueue(TQueue *f, Client c, int size);
void splitter(TQueue &f, int size);
void showQueue(queue<Client> priotity, queue<Client> rest);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    TQueue f;
    int size;

    startQueue(&f);

    do
    {
        cout << "Insira a quantidade de projetos que deseja cadastrar[Máximo de 5 projetos por funcionário]: ";
        cin >> size;
    } while (size > MAXTAM && size < 1);

    signUp(size);
    splitter(f, size);
    showQueue(priorityQueue[MAXTAM], restQueue[MAXTAM]);

    return 0;
}

void startQueue(TQueue *f)
{
    f->start = 0;
    f->end = 0;
    f->amount = 0;
}

void signUp(int size)
{
    Client c;
    TQueue f;
    int size;
    char assistPregnant;

    for (int i = 0; i <= size; i++)
    {
        cin.ignore();
        cout << "Idade: ";
        cin >> c.age;
        cout << "É gestante(s/n)?";
        cin >> assistPregnant;
        (assistPregnant == 's' || assistPregnant == 'S') ? c.pregnant = true : c.pregnant = false;

        insertQueue(&f, c, size);
    }
}

void insertQueue(TQueue *f, Client c, int size)
{
    if (f->amount == MAXTAM)
    {
        cout << "Fila cheia" << end;
        return;
    }

    f->queue1[f->end] = c;
    f->end = (f->end + 1) % MAXTAM;
    f->amount = size;
}

void splitter(TQueue *f, int size)
{
    while (!f->queue1->empty())
    {
        for (int i = 0; i <= f->queue1->size(); i++)
        {
            if (f->queue1[i].front().age <= 60 && f->queue1[i].front().pregnant == true)
            {
                priorityQueue[i].push(f->queue1[i].front());
            }
            else
            {
                restQueue[i].push(f->queue1[i].front());
            }
        }
    }
}

void showQueue(queue<Client> priotity[], queue<Client> rest[])
{

    cout << "Fila Prioritária: " << endl;
    while (!priorityQueue[MAXTAM].empty())
    {
        cout << " " << priorityQueue[MAXTAM].front();
        priorityQueue[MAXTAM].pop();
    }

    cout << "\n\nFila Restante: " << endl;
    while (!restQueue[MAXTAM].empty())
    {
        cout << " " << restQueue[MAXTAM].front();
        priorityQueue[MAXTAM].pop();
    }
}