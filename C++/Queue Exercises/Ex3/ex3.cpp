/*
Pt-BR - Para um dado n´umero inteiro n > 1, o menor inteiro d > 1 que divide n ´e chamado de fator primo.
E poss´ıvel determinar a fatora¸c˜ao prima de n achando-se o fator primo de substituindo n pelo ´
quociente n / d, repetindo essa opera¸c˜ao at´e que n seja igual a 1. Utilizando um dos TADs vistos
em sala (Lista, Pilha ou Fila) para auxili´a-lo na manipula¸c˜ao de dados, implemente uma fun¸c˜ao
que compute a fatora¸c˜ao prima de um n´umero imprimindo os seus fatores em ordem crescente.
Por exemplo, para n = 3960, dever´a ser impresso: 2 * 2 * 2 * 3 * 3 * 5 * 11. 

Eng - For a given integer number n > 1, the smallest integer d > 1 that divides n is called the prime factor.
It is possible to determine the prime factor of n by finding the prime factor of replacing n by the quotient n / d.
quotient n / d, repeating this operation until n equals 1. Using one of the TADs seen
(List, Stack, or Queue) to assist you in data manipulation, implement a function
that computes the prime factor of a number by printing its factors in ascending order.
For example, for n = 3960, it should print: 2 * 2 * 2 * 2 * 3 * 3 * 5 * 11. 

*/
#include <iostream>

using namespace std;

typedef struct queue1
{
    int factor;
    int interaction;
    struct queue1 *next;
} queue1;

void insertQueue(queue1 **f, int x, int y);
void showQueue(queue1 *f);

int main()
{

    int n, p, q, prime, div;
    queue1 *f = NULL;

    cout << "Informe o valor: ";
    cin >> n;
    p = 2;

    while (n > 1)
    {
        q = 0;
        while (n % p == 0)
        {
            q++;
            n = n / p;
        }

        if (q > 0)
            insertQueue(&f, p, q);

        prime = 0;
        while (!prime)
        {
            p++;
            div = 2;
            prime = 1;

            while ((div <= (p / 2)) && prime)
            {
                if (p % div == 0)
                    prime = 0;
                else
                    div = div + 1;
            }
        }
    }

    showQueue(f);

    return 0;
}

void insertQueue(queue1 **f, int x, int y)
{
    queue1 *aux = new queue1;

    aux->factor = x;
    aux->interaction = y;
    aux->next = NULL;

    while (*f != NULL)
        f = &(*f)->next;

    *f = aux;
}

void showQueue(queue1 *f)
{
    queue1 *p = f;

    while (p != NULL)
    {
        cout << "Fator " << p->factor << " com multiplicidade: " << p->interaction << "\n";
        cout << "--------------------------------\n";
        p = p->next;
    }
}