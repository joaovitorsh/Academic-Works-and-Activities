#ifndef LDE_H
#define LDE_H

// ----------------------------- Data Structures -----------------------------

typedef struct item_Type
{
    int id;
    char title[20];
    char description[300];
    char deliveryDate[10];
} item_Type;

typedef struct element_Type *pointer;

typedef struct element_Type
{ // Célula
    item_Type item;
    struct element_Type *next;
    struct element_Type *previous;
} element_Type;

typedef struct list_Type
{
    pointer first;
    pointer last;
} list_Type;

// ----------------------------- Empty list creation and checking functions -----------------------------

void CreateEmptyList(list_Type *list);
bool EmptyListCheck(list_Type *list);

// ----------------------------- List Insertion Functions ----------------------------- 

void InsertListFirst(list_Type *list, item_Type *item);
void InsertListAfterElement(list_Type *list, item_Type *item, int idEleX); // new
void InsertLastList(list_Type *list, item_Type *item);

// ----------------------------- Removal Functions in the List -----------------------------

void RemoveListFirst(list_Type *list, item_Type *item); // new
void RemoveLastList(list_Type *list, item_Type *item);
void RemoveElementXbyId(list_Type *list, item_Type *item, int idEle); // new

// ----------------------------- Search Functions -----------------------------

bool SearchElementXbyId(list_Type *list, item_Type *item, int idEle);
bool SearchElementXbyTitle(list_Type *list, item_Type *item, char title[]);
void SearchWork(list_Type *list);
void SearchByCode(list_Type *list);
void SearchByTitle(list_Type *list);

// ----------------------------- List and Print Functions -----------------------------

void ListWorks(list_Type *list);
void PrintFirstJob(list_Type *list);
void PrintNextJob(list_Type *list, element_Type *ptr);
void PrintPreviousWork(list_Type *list, element_Type *ptr);
void PrintList(list_Type *list);

// ----------------------------- Job listing, registration, and removal functions -----------------------------

int RegisterWork(list_Type *list);
int RemoveWork(list_Type *list);
void RemoveByCode(list_Type *list);
void ListAllWorks(list_Type *list);

// ----------------------------- Menu functions -----------------------------

void Menu();
void MenuRemove();
void MenuSearch();

#endif