#include <iostream>
#include <windows.h>
#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <fstream>
#include "Functions.hpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    createLinkedList(&Staff_List);
   


    menu();
    cout << endl
         << endl;
    system("pause");
    return 0;
}
