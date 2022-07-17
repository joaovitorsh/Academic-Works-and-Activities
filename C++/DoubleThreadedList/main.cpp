#include <iostream>
#include <windows.h>
#include "DoubleThreadedList.cpp"

using namespace std;

int main()
{
    // Double-Threaded List
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    list_Type list;

    CreateEmptyList(&list);
    Menu();

    return 0;
}