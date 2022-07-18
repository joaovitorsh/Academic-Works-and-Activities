/*
    Pt-BR - Dado uma pilha P vazia e uma fila F não vazia, utilizando apenas os testes de fila e pilha vazias,
    as operações Enfileira, Desenfileira, Empilha, Desempilha, e uma variável auxiliar, escreva uma
    função que inverta a ordem dos elementos da fila.

    Eng - Given an empty stack P and a non-empty queue F, using only the empty queue and empty stack tests,
    the operations Queue, Un Queue, Stack, Unstack, and an auxiliary variable, write a function that
    function that reverses the order of the elements in the queue.
*/

#include <iostream>
#include <windows.h>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

stack<int> p;
queue<int> f;

void exchange(stack<int> p, queue<int> *f);
void showQueue(queue<int> f);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < v1.size(); i++)
    {
        f.push(v1[i]);
    }

    exchange(p, &f);
    showQueue(f);

    return 0;
}

void exchange(stack<int> p, queue<int> *f)
{

    while (!f->empty())
    {
        p.push(f->front());
        f->pop();
    }

    while (!p.empty())
    {
        f->push(p.top());
        p.pop();
    }
}

void showQueue(queue<int> f)
{

    while (!f.empty())
    {
        cout << " " << f.front();
        f.pop();
    }
}