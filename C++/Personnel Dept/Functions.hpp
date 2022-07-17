#ifndef FUNCTION_H
#define FUNCTION_H

#define MAXTAM 5

typedef int tKey; //...

typedef struct tCell_Str *tPointer; //...

typedef struct
{
    tKey project_code;     // codigo do projeto
    char name_project[30]; // nome do projeto
    float hours;           // numero de horas trabalhas por semana no projeto
} tProject;                // struct que armazena os dados dos projetos

typedef struct
{
    tProject item_project[MAXTAM]; 
    int first_project;
    int last_project;
    int size_project;
} tSequential_list;

typedef struct
{
    tKey staff_code;          // código do funcionário(não existem funcionários com o mesmo código)
    char name[40];            // nome do funcionário
    char address[60];         // endereço do funcionário
    int num_dependents;       // número de dependentes do funcionário
    int num_projects = 0;     // número de projetos que o funcionário está(limite até 5 projetos)
    tSequential_list project; // {"Projeto 1", "Projeto 2", ... }

} tStaff; // struct que armazena os dados dos funcionários

typedef struct tCell_Str
{
    tStaff item;
    tPointer next;
} tCell; //...

typedef struct
{
    tPointer first;
    tPointer last;
} tLinked_list; //...

bool linear_list_created = false;

void createLinkedList(tLinked_list *Staff_List); // Cria a lista encadeada de funcionários vazia

int checksEmptyLinkedList(tLinked_list Staff_List); // verifica a lista se está vazia ou cheia

void createLinearList(tSequential_list &Project_List); // cria a linear de projetos vazia

int verifyEmptyLinearList(tSequential_list &Project_List); // verifica se a lista está vazia ou cheia

void insertStaff(tStaff f, tLinked_list *Staff_List); // Insere funcionário

void insertProject(tProject p, tSequential_list &Project_List); // Insere Projeto

void registerStaff(tLinked_list *Staff_List, tSequential_list Project_List); // Cadastra o funcionário e os seus projetos

int staffResearch(tKey code, tPointer *p); // Função que pesquisa o funcionário e retorna para a função de consulta de funcionário

void staffConsultation(tLinked_list *Staff_List); // Consulta funcionário

void deleteStaff(tPointer p, tLinked_list *Staff_List, tStaff *e); // Função que apaga o funcionário e retorna para a função de exclusão de funcionário

void excludeStaff(tLinked_list *Staff_List); // Exclui funcionário

void includesProjects(tLinked_list *Staff_List); // Inclui projetos a um funcionário

int projectResearch(tSequential_list Project_List, int code, int *p);

void printPaycheck(tLinked_list Staff_List); // imprime o contra cheque dos funcionários

void excludeProjects(tLinked_list *Staff_List, tSequential_list Project_List); // exclui projetos

void printList(tLinked_list *Staff_List); // função pra printar a lista de funcionários

void getStaff(); // Usada para chamar os dados do arquivo ao iniciar o programa

void saveStaff(); // Função para salvar os dados no arquivo

int hours(tSequential_list Project_List); // Retorna o total de horas trabalhadas por semana pelo funcionário

void removeSequence(int p, tSequential_list *Project_List, tProject *q); // Remove o projeto da sequencia de projetos

int foundLinkedList(tKey code, tLinked_list Staff_List, tPointer *p); // Encontra um item dentro da lista encadeada

void menu(); // menu do projeto

tSequential_list Project_List;
tLinked_list Staff_List;

#include "Functions.cpp"
#endif