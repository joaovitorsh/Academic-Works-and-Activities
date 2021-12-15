#include <iostream>
#include <windows.h>
#include <time.h>
#include <math.h>
#include "./src/linkedlist.hpp"
#include "./src/stack.hpp"
#include "./src/dqueue.hpp"

using namespace std;

#define MAXTAM 10
#define MAX_DELIVERY 7

typedef struct
{
    string name;
    int cod;
    float value;
} Product;

typedef struct
{
    int cod_order;
    LinkedList<Product> *products = create<Product>();
    float value;
    float distance;
} Order;

Product menu[MAXTAM];                                  // Cardapio
DQueue<Order> *order_list = createDQueue<Order>();     // Fila de Pedidos
Stack<Order> *backpack = createS<Order>(MAX_DELIVERY); // Mochila

void register_order();

void main_menu();
void print_menu_product();
void mount_menu();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    mount_menu();
    main_menu();
    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}

void register_order()
{
    int cod;
    char choose;

    cout << "██████████████████████████████████████████████\n";
    cout << "██             REGISTRO DE PEDIDO           ██\n";
    cout << "██████████████████████████████████████████████\n\n";

    //order_list.cod_order += 1;
    Order o;
    o.cod_order = (order_list->size + 10);

    do
    {
        cout << "Digite o codigo do produto: ";
        cin >> cod;

        // Procura codigo do produto
        for (int i = 0; i < MAXTAM; i++)
        {
            if (cod == menu[i].cod)
            {
                // adiciona o produto encontrado à lista de produtos do pedido
                insertItem<Product>(menu[i], o.products);
                o.value += menu[i].value;
                cout << "Produto foi inserido à lista de pedidos!";
                break;
            }
            else if (i == (MAXTAM - 1))
            {
                cout << "Produto nao encontrado!";
            }
        }

        cout << "\nDeseja inserir outro produto ao pedido?(S/N) ";
        cin >> choose;
    } while (choose == 's' || choose == 'S');
    o.distance = 1 + (rand() % 25);
    if (isEmptyL(o.products))
    {
        cout << "Pedido não foi inserido à fila!";
        return;
    }

    //colocando na fila o pedido
    cout << "Pedido " << (enqueueDQueue(order_list, o) ? "" : "nao ") << "foi inserido à fila de pedidos!";
}

void printProduct(Product p)
{
    cout << "\n\tCodigo: " << p.cod << "\tNome: " << p.name << "\tPreco: " << p.value;
}

void printOrder(Order o)
{
    cout << "\nPEDIDO: ";
    cout << "\nCodigo: " << o.cod_order
         << "\nValor Total: " << o.value
         << "\nDistancia: " << o.distance
         << "\nProdutos: ";
    printList(o.products, printProduct);
    cout
        << endl;
}

void print_orders()
{
    printDQueue(order_list, printOrder);
}

void mount_menu()
{
    srand(time(NULL));

    string names[] = {
        "Pizza de Calabresa   ",
        "Pizza Portuguesa     ",
        "Pizza Bolonhesa      ",
        "Pizza Canadense      ",
        "Pizza Tradicional    ",
        "Pizza Americana      ",
        "Pizza de Chocolate   ",
        "Pizza de Frango      ",
        "Pizza de Marguerita  ",
        "Pizza Mexicana       ",
    };

    for (int i = 0; i < MAXTAM; i++)
    {
        menu[i].cod = 10 + i;
        menu[i].name = names[i];
        menu[i].value = 30 + (rand() % 50); // adicionar um valor aleatório ao produto entre 30 a 50 reais.
    }
}

void print_menu_product()
{
    const int cols = 3;
    for (int i = 0; i < ceil((double)MAXTAM / cols); i++)
    {
        cout << "\n-------------------------------------------------------------------------------------------------\n";

        for (int j = 0; j < cols; j++)
        {
            if (cols * i + j >= MAXTAM)
            {
                break;
            }
            cout << "|  Codigo: " << menu[cols * i + j].cod << "\t\t\t";
        }
        cout << endl;
        for (int j = 0; j < cols; j++)
        {
            if (cols * i + j >= MAXTAM)
            {
                break;
            }
            cout << "|  Nome: " << menu[cols * i + j].name << "\t";
        }
        cout << endl;
        for (int j = 0; j < cols; j++)
        {
            if (cols * i + j >= MAXTAM)
            {
                break;
            }
            cout << "|  Preço: " << menu[cols * i + j].value << "\t\t\t";
        }
    }
    cout << "\n-------------------------------------------------------------------------------------------------\n";
}

void consult_order()
{
    cout << "Digite o codigo do pedido: ";
    int cod;
    cin >> cod;
    NodeDQueue<Order> *node = order_list->front;
    for (int i = 0; i < order_list->size; i++)
    {
        if (node->item.cod_order == cod)
        {
            printOrder(node->item);
            return;
        }
        node = node->next;
    }
    cout << "Nao foi encontrado este pedido!";
}

//TODO -> ha um problema nesta funcao
void print_delivery_list()
{ // Acho que essa funciona

    // Pegar a qtd max que a mochila pode
    Order auxList[MAX_DELIVERY];
    Order o;
    int actual_size_bp = 0;
    for (int i = 0; i < MAX_DELIVERY; i++)
    {
        if (!dequeueDQueue(order_list, &o))
        {
            break;
        }
        auxList[i] = o;
        actual_size_bp++;
    }

    // ordenar

    for (int i = 0; i < actual_size_bp; i++)
    {
        for (int j = i; j < actual_size_bp; j++)
        {
            if (auxList[i].distance < auxList[j].distance)
            {
                o = auxList[i];
                auxList[i] = auxList[j];
                auxList[j] = o;
            }
        }
    }
    // colocar na mochila

    for (int i = 0; i < actual_size_bp; i++)
    {
        push(backpack, auxList[i]);
    }

    //imprimir

    cout << "MOCHILA: \n";
    printStack(backpack, printOrder);
}

void post_delivery()
{
    Order o;
    if (!pop(backpack, &o))
    {
        cout << "Não foi possivel lancar entrega!\n";
        return;
    }
    cout << "PEDIDO ENTREGUE: \n";
    printOrder(o);
}

void main_menu()
{
    int option;
    do
    {
        system("cls");

        cout << " \n    ████████████████████████████████████████████████████████████\n";
        cout << "                            SISTEMA DE DELIVERY                    ";
        cout << " \n    ██                                                        ██";
        cout << " \n    ████████████████████████████████████████████████████████████\n";
        cout << " \n    ██             1 - Incluir um novo pedido                 ██";
        cout << " \n    ██             2 - Listar pedidos                         ██";
        cout << " \n    ██             3 - Ver Cardápio                           ██";
        cout << " \n    ██             4 - Consultar pedido                       ██";
        cout << " \n    ██             5 - Imprimir lista de entrega              ██";
        cout << " \n    ██             6 - Lançar entrega                         ██";
        cout << " \n    ██             7 - Sair                                   ██";
        cout << " \n    ████████████████████████████████████████████████████████████\n";

        while ((cout << "\n Digite o numero referente a sua opçao: ") && !(cin >> option))
        {
            cout << "  \n        Digite uma opção válida.";
            cin.clear();
            cin.ignore();
            Sleep(1000);
            system("cls");
            main_menu();
        }
        switch (option)
        {
        case 1:
            register_order();
            break;

        case 2:
            print_orders();
            break;

        case 3:
            print_menu_product();
            break;

        case 4:
            consult_order();
            break;

        case 5:
            print_delivery_list();
            break;
        case 6:
            post_delivery();
            break;
        default:
            break;
        }
        system("pause");
    } while (option != 7);
}