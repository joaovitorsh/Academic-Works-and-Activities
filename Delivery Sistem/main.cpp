#include <iostream>
#include <windows.h>
#include <time.h>
#include <math.h>
#include "./src/linkedlist.hpp"
#include "./src/stack.hpp"

using namespace std;

#define MAXTAM 10
#define MAX_DELIVERY 7
#define QTD_PRODS 5

typedef struct
{
    string name; // char name[30]; <--- Troquei, ah vai dar problema demais kk
    int cod;
    float value;
} Product;

typedef struct
{
    int cod_order;
    LinkedList<Product> *products = create<Product>(); // int product[MAXTAM];
    float order_value;
    float distance;
} Order;

Product menu[MAXTAM]; // Cardapio
Order Order_List;

void register_order();

void main_menu();
void print_menu_product();
void mount_menu();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    Stack<Order> *backpack = createS<Order>(MAX_DELIVERY);

    mount_menu();
    main_menu();
    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}

void register_order()
{
    int cod;
    char choose, option;

    do{ 
    cout << "██████████████████████████████████████████████\n";
    cout << "██             REGISTRO DE PEDIDO           ██\n";
    cout << "██████████████████████████████████████████████\n\n";

    Order_List.cod_order+= 1;

    do
    {
        
        Order_List.distance = 1 + (rand() % 25);

        cout << "Digite o codigo do produto: ";
        cin >> cod;

        // Procura codigo
        for (int i = 0; i < MAXTAM; i++)
        {
            if (cod == menu[i].cod)
            {
                Order_List.order_value =+ menu[i].value;
                 // usar a função de inserir o produto no pedido na lista encadeada
            }
        }
    } while (choose == 's' || choose == 'S');

    } while (option == 's' || option == 'S');
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
        menu[i].cod = 10 + (rand() % 100);
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
    }
    cout << "\n-------------------------------------------------------------------------------------------------\n";
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

        system("cls");

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

            break;

        case 2:

            break;

        case 3:
            print_menu_product();
            break;

        case 4:

            break;

        case 5:

            break;
        case 6:

            break;
        default:
            system("pause");
            break;
        }
        system("pause");
    } while (option != 7);
}