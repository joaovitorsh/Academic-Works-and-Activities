#include <iostream>
#include <windows.h>
#include <string.h>
#include "DoubleThreadedList.hpp"

using namespace std;

// ----------------------------- Empty list creation and checking functions -----------------------------

void CreateEmptyList(list_Type *list)
{
    list->first = new element_Type;
    list->last = list->first;
    list->first->next = NULL;
    list->first->previous = NULL;
}

bool EmptyListCheck(list_Type *list)
{
    return (list->first == list->last);
}

// ----------------------------- List Insertion Functions -----------------------------

void InsertListFirst(list_Type *list, item_Type *item)
{
    pointer assist;
    assist = list->first->next;
    list->first->next = new element_Type;
    list->first->next->next = assist;
    list->first->next->item = *item;
    assist->previous = list->first->next;
    list->first->next->previous = list->first;
}

void InsertListAfterElement(list_Type *list, item_Type *item, int idEleX)
{
    pointer assist, x, itemPrevious;
    x = list->first;

    while (x->next != NULL)
    {
        if (x->next->item.id == idEleX)
        {
            itemPrevious = x->next;
            break;
        }
        x = x->next;
    }

    assist = itemPrevious->next;
    itemPrevious->next = new element_Type;
    itemPrevious->next->item = *item;
    itemPrevious->next->next = assist;
    assist->previous = itemPrevious->next;
    assist->previous->previous = itemPrevious;
}

void InsertLastList(list_Type *list, item_Type *item)
{
    pointer assist;
    assist = list->last;
    list->last->next = new element_Type;
    list->last = list->last->next;
    list->last->item = *item;
    list->last->next = NULL;
    list->last->previous = assist;
}

// ----------------------------- Removal Functions in the List -----------------------------

void RemoveListFirst(list_Type *list, item_Type *item)
{
    pointer assist;

    if (EmptyListCheck(list))
    {
        return;
    }
    *item = list->first->next->item;
    assist = list->first->next;
    list->first->next = assist->next;
    list->first->next->previous = list->first;
    free(assist);
}

void RemoveLastList(list_Type *list, item_Type *item)
{
    pointer assist, previous, x;

    if (EmptyListCheck(list))
    {
        return;
    }

    x = list->first;
    while (x != NULL)
    {
        if (x->next == list->last)
        {
            previous = x;
            break;
        }
        x = x->next;
    }

    assist = list->last;
    list->last = previous;
    *item = assist->item;
    list->last->next = NULL;
    free(assist);
}

void RemoveElementXbyId(list_Type *list, item_Type *item, int idEle)
{
    pointer assist, previous, x;

    if (EmptyListCheck(list))
    {
        return;
    }

    x = list->first;

    while (x != NULL)
    {
        if (x->next->item.id == idEle)
        {
            previous = x;
            break;
        }
        x = x->next;
    }
    assist = previous->next;
    previous->next = assist->next;
    *item = assist->item;
    free(assist);
}

// ----------------------------- Search functions -----------------------------

bool SearchElementXbyId(list_Type *list, item_Type *item, int idEle)
{
    pointer x;

    if (EmptyListCheck(list))
    {
        return false;
    }

    x = list->first;

    while (x != NULL)
    {
        if (x->next->item.id == idEle)
        {
            *item = x->next->item;
            return true;
        }
        x = x->next;
    }
    return false;
}

bool SearchElementXbyTitle(list_Type *list, item_Type *item, char title[])
{
    pointer x;

    if (EmptyListCheck(list))
    {
        return false;
    }

    x = list->first;

    while (x != NULL)
    {
        if (strcmpi(x->next->item.title, title) == 0)
        {
            *item = x->next->item;
            return true;
        }
        x = x->next;
    }
    return false;
}

void SearchWork(list_Type *list)
{
    int menu_option;
    do
    {
        MenuSearch();
        while ((cout << "  \n        Escolha uma opção: ") && !(cin >> menu_option))
        {
            cout << "  \n        Digite um valor válido.";
            cin.clear();
            cin.ignore();
            Sleep(1000);
            system("cls");
            MenuSearch();
        }
        switch (menu_option)
        {
        case 1:
            SearchByCode(list);
            system("pause");
            system("cls");
            break;
        case 2:
            SearchByTitle(list);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            break;
        default:
            SearchWork(list);
        }
    } while (menu_option > 3 && menu_option < 1);
}

void SearchByCode(list_Type *list)
{
    item_Type item;
    int code;

    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                     PESQUISA POR CÓDIGO                     ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████";

    while ((cout << "  \n\n        Informe o código do trabalho a ser pesquisado: ") && !(cin >> code))
    {
        cout << "Digite um valor numérico.\n";
        cin.clear();
        cin.ignore();
    }
    if (SearchElementXbyId(list, &item, code))
    {
        cout << endl
             << endl
             << "Código: " << item.id << endl;
        cout << "Título: " << item.title << endl;
        cout << "Descrição: " << item.description << endl;
        cout << "Data de Entrega: " << item.deliveryDate << endl
             << endl;
    }
    else
    {
        cout << "\n\nCódigo não encontrado.\n\n";
    }
}

void SearchByTitle(list_Type *list)

{
    item_Type item;
    char title[20];

    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                     PESQUISA POR TÍTULO                     ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████";

    cin.ignore();
    cout << "  \n\n        Informe o título do trabalho a ser pesquisado: ";
    gets(title);

    if (SearchElementXbyTitle(list, &item, title))
    {
        cout << endl
             << endl
             << "Código: " << item.id << endl;
        cout << "Título: " << item.title << endl;
        cout << "Descrição: " << item.description << endl;
        cout << "Data de Entrega: " << item.deliveryDate << endl
             << endl;
    }
    else
    {
        cout << "\n\nTítulo não encontrado.\n\n";
    }
}

// ----------------------------- List and Print Functions -----------------------------

void ListWorks(list_Type *list)
{
    system("cls");
    char nav;

    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                    TRABALHOS CADASTRADOS                    ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████\n\n";

    if (EmptyListCheck(list))
    {
        cout << "Nenhum trabalho cadastrado.\n\n";
        system("pause");
        system("cls");
        return;
    }

    PrintFirstJob(list);
    while ((cout << "(a) anterior || (p) próximo || (c) cancelar: ") && !(cin >> nav))
    {
        cout << "Digite um valor válido.\n";
        cin.clear();
        cin.ignore();
    }

    if (nav == 'p')
    {
        pointer p = list->first->next->next;
        PrintNextJob(list, p);
    }
    else if (nav == 'a')
    {
        pointer p = list->first;
        PrintPreviousWork(list, p);
    }
    else
    {
        system("cls");
        return;
    }
}

void PrintFirstJob(list_Type *list)
{
    pointer x;

    x = list->first->next;

    cout << "Código: " << x->item.id << endl;
    cout << "Título: " << x->item.title << endl;
    cout << "Descrição: " << x->item.description << endl;
    cout << "Data de Entrega: " << x->item.deliveryDate << endl
         << endl;
}

void PrintNextJob(list_Type *list, element_Type *ptr)
{
    pointer p;
    char nav;

    for (p = ptr; p != NULL; p = p->next)
    {
        system("cls");

    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                    TRABALHOS CADASTRADOS                    ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████\n\n";

        cout << "Código: " << p->item.id << endl;
        cout << "Título: " << p->item.title << endl;
        cout << "Descrição: " << p->item.description << endl;
        cout << "Data de Entrega: " << p->item.deliveryDate << endl
             << endl;
        while ((cout << "(a) anterior || (p) próximo || (c) cancelar: ") && !(cin >> nav))
        {
            cout << "Digite um valor válido.\n";
            cin.clear();
            cin.ignore();
        }
        if (nav == 'p')
        {
            continue;
        }
        else if (nav == 'a')
        {
            PrintPreviousWork(list, p->previous);
        }
        else
        {
            system("cls");
            return;
        }
    }

    if (p == NULL)
    {
        cout << "\nNão há mais trabalhos cadastrados.\n\n";
        system("pause");
        system("cls");
        return;
    }
}

void PrintPreviousWork(list_Type *list, element_Type *ptr)
{
    pointer p;
    char nav;

    if (ptr == list->first)
    {
        cout << "\nNão há trabalhos cadastrados anteriores a este.\n\n";
        system("pause");
        system("cls");
        return;
    }

    for (p = ptr; p != NULL; p = p->previous)
    {
        system("cls");

    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                    TRABALHOS CADASTRADOS                    ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████\n\n";

        cout << "Código: " << p->item.id << endl;
        cout << "Título: " << p->item.title << endl;
        cout << "Descrição: " << p->item.description << endl;
        cout << "Data de Entrega: " << p->item.deliveryDate << endl
             << endl;
        while ((cout << "(a) anterior || (p) próximo || (c) cancelar: ") && !(cin >> nav))
        {
            cout << "Digite um valor válido.\n";
            cin.clear();
            cin.ignore();
        }
        if (nav == 'a')
        {
            if (p == list->first->next)
            {
                return;
            }
            else
            {
                continue;
            }
        }
        else if (nav == 'p')
        {
            PrintNextJob(list, p->next);
        }
        else
        {
            system("cls");
            return;
        }
    }
}

void PrintList(list_Type *list)
{
    pointer x;

    x = list->first->next;

    while (x != NULL)
    {
        cout << endl
             << endl
             << "Código: " << x->item.id << endl;
        cout << "Título: " << x->item.title << endl;
        cout << "Descrição: " << x->item.description << endl;
        cout << "Data de Entrega: " << x->item.deliveryDate << endl;
        x = x->next;
    }
}

// ----------------------------- Job listing, registration, and removal functions -----------------------------

int RegisterWork(list_Type *list)
{
    system("cls");

    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                     CADASTRO DE TRABALHO                    ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████";

    item_Type item;

    while ((cout << "\n\n1. Código: ") && !(cin >> item.id))
    {
        cout << "Digite um valor numérico.\n";
        cin.clear();
        cin.ignore();
    }
    cin.ignore();

    cout << "2. Título: ";
    gets(item.title);
    cout << "3. Descrição: ";
    gets(item.description);
    cout << "4. Data de Entrega: ";
    gets(item.deliveryDate);

    InsertLastList(list, &item);

    cout << "\nTrabalho cadastrado com sucesso!\n\n";
    system("pause");
    system("cls");
}

int RemoveWork(list_Type *list)
{
    system("cls");

    item_Type item;

    int menu_option;
    do
    {
        MenuRemove();
        while ((cout << "  \n        Escolha uma opção: ") && !(cin >> menu_option))
        {
            cout << "  \n        Digite um valor válido.";
            cin.clear();
            cin.ignore();
            Sleep(1000);
            system("cls");
            MenuRemove();
        }
        system("cls");
        switch (menu_option)
        {
        case 1:
            RemoveListFirst(list, &item);
            MenuRemove();
            cout << "\n\nTrabalho removido com sucesso!\n\n";
            system("pause");
            system("cls");
            break;
        case 2:
            RemoveLastList(list, &item);
            MenuRemove();
            cout << "\n\nTrabalho removido com sucesso!\n\n";
            system("pause");
            system("cls");
            break;
        case 3:
            RemoveByCode(list);
            cout << "\n\nTrabalho removido com sucesso!\n\n";
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            break;
        default:
            RemoveWork(list);
        }
    } while (menu_option > 4 && menu_option < 1);
}

void RemoveByCode(list_Type *list)
{
    item_Type item;
    int cod;
    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                     EXCLUSÃO DE TRABALHO                    ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████\n";

    while ((cout << "  \n        Informe o código do trabalho a ser removido: ") && !(cin >> cod))
    {
        cout << "Digite um valor numérico.\n";
        cin.clear();
        cin.ignore();
    }
    RemoveElementXbyId(list, &item, cod);
}

void ListAllWorks(list_Type *list)
{
    system("cls");

    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                    TRABALHOS CADASTRADOS                    ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████\n\n";

    PrintList(list);
    cout << endl
         << endl;
    system("pause");
    system("cls");
}

// ----------------------------- Menu functions -----------------------------

void Menu()
{
    list_Type list;
    int menu_option;
    do
    {
        cout << "  \n        █████████████████████████████████████████████████████████████████";
        cout << "  \n        ██                    TRABALHOS ACADÊMICOS                     ██";
        cout << "  \n        █████████████████████████████████████████████████████████████████";
        cout << "  \n        ██                                                             ██";
        cout << "  \n        ██ 1 - INCLUIR NOVO TRABALHO                                   ██";
        cout << "  \n        ██ 2 - REMOVER UM TRABALHO                                     ██";
        cout << "  \n        ██ 3 - NAVEGAR PELOS TRABALHOS                                 ██";
        cout << "  \n        ██ 4 - PESQUISAR UM TRABALHO                                   ██";
        cout << "  \n        ██ 5 - LISTAR TODOS OS TRABALHOS                               ██";
        cout << "  \n        ██ 6 - SAIR                                                    ██";
        cout << "  \n        ██                                                             ██";
        cout << "  \n        █████████████████████████████████████████████████████████████████\n\n";

        while ((cout << "  \n        Informe uma opção: ") && !(cin >> menu_option))
        {
            cout << "  \n        Digite um valor válido.";
            cin.clear();
            cin.ignore();
            Sleep(800);
            system("cls");
            Menu();
        }

        switch (menu_option)
        {
        case 1:
            RegisterWork(&list);
            break;
        case 2:
            RemoveWork(&list);
            break;
        case 3:
            ListWorks(&list);
            break;
        case 4:
            SearchWork(&list);
            break;
        case 5:
            ListAllWorks(&list);
            break;
        case 6:
            cout << "Aguardamos você em breve novamente\n\n";
            break;
        }
    } while (menu_option != 6);
}

void MenuRemove()
{
    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                      EXCLUIR TRABALHO                       ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                                                             ██";
    cout << "  \n        ██ 1 - PRIMEIRO DA LISTA                                       ██";
    cout << "  \n        ██ 2 - ÚLTIMO DA LISTA                                         ██";
    cout << "  \n        ██ 3 - POR CÓDIGO                                              ██";
    cout << "  \n        ██ 4 - VOLTAR                                                  ██";
    cout << "  \n        ██                                                             ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████\n\n";
}

void MenuSearch()
{
    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                      PESQUISAR TRABALHO                     ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████";
    cout << "  \n        ██                                                             ██";
    cout << "  \n        ██ 1 - POR CÓDIGO                                              ██";
    cout << "  \n        ██ 2 - POR TÍTULO                                              ██";
    cout << "  \n        ██ 3 - VOLTAR                                                  ██";
    cout << "  \n        ██                                                             ██";
    cout << "  \n        █████████████████████████████████████████████████████████████████\n\n";
}