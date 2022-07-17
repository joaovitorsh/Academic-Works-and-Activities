#include <iostream>
#include <windows.h>
#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <fstream>
#include "Functions.hpp"

using namespace std;

void createLinkedList(tLinked_list *Staff_List)
{
    Staff_List->first = new tCell;
    Staff_List->last = Staff_List->first;
    Staff_List->first->next = NULL;
}

int ChecksEmptyLinkedList(tLinked_list Staff_List)
{
    return (Staff_List.first == Staff_List.last);
}

void createLinearList(tSequential_list *Project_List)
{
    Project_List->first_project = 0;
    Project_List->last_project = 0;
    Project_List->size_project = 0;
    linear_list_created = true;
}

int verifyEmptyLinearList(tSequential_list &Project_List)
{
    if (Project_List.size_project == 0 && linear_list_created)
    {
        return 1;
    }
    else if (!linear_list_created)
    {
        return -1;
    }
    else
        return 0;
}

void insertStaff(tStaff f, tLinked_list *Staff_List)
{
    Staff_List->last->next = new tCell;
    Staff_List->last = Staff_List->last->next;
    Staff_List->last->item = f;
    Staff_List->last->next = NULL;
}

void insertProject(tProject p, tSequential_list *Project_List)
{
    if (Project_List->last_project < MAXTAM)
    {
        Project_List->item_project[Project_List->last_project] = p;
        Project_List->last_project++;
    }
}

void registerStaff(tLinked_list *Staff_List, tSequential_list Project_List)
{
    tStaff f;
    tProject p;
    int num;
    char option, choose;
    srand(time(NULL)); // Faz com que gere um número aleatório baseado na hora do computador

    do
    {
        int id = 1000 + (rand() % 9999);
        f.staff_code = id;

        cout << "██████████████████████████████████████████████\n";
        cout << "██          CADASTRO DE FUNCIONÁRIO         ██\n";
        cout << "██████████████████████████████████████████████\n\n";
        cin.ignore();
        cout << "Nome do funcionário: ";
        gets(f.name);
        cout << "Endereço: ";
        gets(f.address);
        cout << "Número de dependentes: ";
        cin >> f.num_dependents;

        createLinearList(&f.project);

        cout << "\n\n█████████████████████████████\n";
        cout << "██        PROJETOS         ██\n";
        cout << "█████████████████████████████\n\n";

        cout << "Deseja registrar um projeto?[s/n] ";
        cin >> option;

        if (option == 's' || option == 'S')
        {

            do
            {
                cout << "Insira a quantidade de projetos que deseja cadastrar[Máximo de 5 projetos por funcionário]: ";
                cin >> num;
                f.num_projects = num;

            } while (num > MAXTAM && num < 1);

            Project_List.size_project = f.num_projects;

            for (int i = 0; i < num; i++)
            {

                int id = 1 + (rand() % 999);
                p.project_code = id;

                cin.ignore();
                cout << "Nome do projeto: ";
                gets(p.name_project);

                cout << "Numero de horas trabalhada: ";
                cin >> p.hours;

                insertProject(p, &f.project);
            }
        }

        insertStaff(f, Staff_List);

        system("cls");
        printList(Staff_List);

        cout << "\nDeseja cadastrar outro funcionário?[s/n]  ";
        cin >> choose;
        if (choose == 'n' || choose == 'N')
        {
            break;
        }

    } while (choose != 'n' || choose != 'N');

    cout << "\nFuncionário cadastrado com sucesso!\n\n";
    cout << "Voltando ao menu pricipal, aguarde";
    for (int i = 0; i < 7; i++)
    {
        Sleep(300);
        cout << ". ";
    }
    system("cls");
}

int staffResearch(tKey code, tPointer *p)
{
    tPointer aux = Staff_List.first;
    while (aux->next != NULL)
    {
        if (aux->next->item.staff_code == code)
        {
            *p = aux;
            return 1;
        }
        else
        {
            aux = aux->next;
            *p = aux;
        }
    }
    return 0;
}

void staffConsultation(tLinked_list *Staff_List)
{
    int ret;
    int code;
    char option;
    tPointer p;

    cout << "█████████████████████████████████████████████████████\n";
    cout << "██               CONSULTA FUNCIONÁRIO              ██\n";
    cout << "█████████████████████████████████████████████████████\n\n";

    do
    {

        cout << "Informe o código do funcionário: ";
        cin >> code;

        ret = staffResearch(code, &p);

        if (ret == 1)
        {
            cout << "\nCódigo do Funcionário: " << p->next->item.staff_code;
            cout << "\nNome: " << p->next->item.name;
            cout << "\nEndereço: " << p->next->item.address;
            cout << "\nQuantidade de dependentes: " << p->next->item.num_dependents;
            cout << "\nNúmero de projetos que o funcionário está: " << p->next->item.num_projects << endl
                 << endl;

            if (verifyEmptyLinearList(Project_List) != 1)
            {
                for (int i = 0; i < p->next->item.num_projects; i++)
                {
                    cout << "\nCódigo do Projeto: " << p->next->item.project.item_project->project_code;
                    cout << "\nNome do Projeto: " << p->next->item.project.item_project->name_project;
                    cout << "\nHoras trabalhadas neste projeto: " << p->next->item.project.item_project->hours << endl
                         << endl;
                }
            }
            cout << "\n\nDeseja pesquisar por outro funcionário?[s/n]  ";
            cin >> option;
            if (option == 'n')
            {
                cout << "Voltando ao menu principal, aguarde";
                for (int i = 0; i < 7; i++)
                {
                    Sleep(300);
                    cout << ". ";

                    break;
                }
            }
        }
        else
        {
            cout << "\nFuncionário não encontrado.\n";
            cout << "\n\nDeseja pesquisar por outro funcionário?[s/n]  ";
            cin >> option;
            if (option == 'n')
            {
                cout << "Aguarde";
                for (int i = 0; i < 7; i++)
                {
                    Sleep(400);
                    cout << ". ";
                    break;
                }
                system("cls");
            }
        }
    } while (option != 'n');
}

void includesProjects(tLinked_list *Staff_List)
{
    tProject pj;
    tStaff f;
    tPointer p;
    char option, choose;

    do
    {

        staffConsultation(Staff_List);

        cout << "Deseja registrar um projeto?[s/n] ";
        cin >> option;
        if (option == 's' || option == 'S')
        {

            if (p->next->item.num_projects < MAXTAM && p->next->item.num_projects >= 1)
            {
                f.num_projects++;
                for (int i = 0; i < f.num_projects; i++)
                {

                    int id = 1 + (rand() % 999);
                    pj.project_code = id;

                    cin.ignore();
                    cout << "Nome do projeto: ";
                    gets(pj.name_project);

                    cout << "Numero de horas trabalhada: ";
                    cin >> pj.hours;

                    insertProject(pj, &(p->next->item.project));
                }
            }
            else
            {
                cout << "Limite de projetos alcançados, não é possível adicionar mais projetos";
                cout << "\nDeseja pesquisar por outro funcionário?[s/n]  ";
                cin >> choose;
                if (choose == 'n')
                {
                    break;
                }
            }
        }
        else
        {
            cout << "\nDeseja incluir projetos em outro funcionário?[s/n]  ";
            cin >> choose;
            if (choose == 'n')
            {
                break;
            }
        }
    } while (choose != 'n');

    cout << "\nDeseja voltar ao menu principal?[s/n]  ";
    cin >> choose;
    if (choose == 'n')
    {
        cout << "\nPrograma finalizado.";
        system("pause");
    }
    else
    {
        cout << "Voltando ao menu principal, aguarde";
        for (int i = 0; i < 7; i++)
        {
            Sleep(300);
            cout << ". ";
            system("cls");
        }
    }
}

void deleteStaff(tPointer p, tLinked_list *Staff_List, tStaff *e)
{
    tPointer x;

    if ((ChecksEmptyLinkedList(*Staff_List)) || (p == NULL) || (p->next == NULL))
    {
        cout << "Erro. Lista vazia";
    }
    else
    {
        x = p->next;
        *e = x->item;
        p->next = x->next;
        if (p->next == NULL)
        {
            Staff_List->last = p;
        }
        delete x;
    }
}

void excludeStaff(tLinked_list *Staff_List)
{
    tStaff f;
    tPointer x = Staff_List->first;
    char choose;
    int option, option2;
    int cont = 0;

    do
    {
        cout << "███████████████████████████████████████████\n";
        cout << "██        EXCLUSÃO DE FUNCIONÁRIO        ██\n";
        cout << "███████████████████████████████████████████\n\n";

        cout << "\n1 - Excluir um funcionário específico";
        cout << "\n2 - Excluir todos os funcionários que não possuem projetos\n";
        cin >> option;
        system("cls");

        switch (option)
        {
        case 1:
            do
            {
                staffConsultation(Staff_List);

                cout << "\n1 - Excluir este funcionário";
                cout << "\n2 - Pesquisar por outro funcionário\n";
                cin >> option2;

                if (option2 == 1)
                {
                    cout << "Excluindo o funcionário, " << x->next->item.name << " aguarde";
                    for (int i = 0; i < 7; i++)
                    {
                        Sleep(300);
                        cout << ". ";
                    }

                    deleteStaff(x, Staff_List, &f);
                    cont++;

                    cout << "Exclusão feita com sucesso!" << endl
                         << endl;

                    cout << "\nDeseja voltar ao menu principal?[s/n]  ";
                    cin >> choose;
                    if (choose == 'n')
                    {
                        cout << "\nPrograma finalizado.";
                        system("pause");
                    }
                    else
                    {
                        cout << "Voltando ao menu pricipal, aguarde";
                        for (int i = 0; i < 7; i++)
                        {
                            Sleep(300);
                            cout << ". ";
                            system("cls");
                        }
                    }
                }

            } while (option2 != 1);
            break;
        case 2:
            cout << "Excluindo todos os funcionários que não possuem projetos, aguarde";
            for (int i = 0; i < 7; i++)
            {
                Sleep(300);
                cout << ". ";
            }
            while (x != NULL)
            {
                if (verifyEmptyLinearList(Project_List) == 1) // Verificar se funcionário não possui projetos
                {
                    deleteStaff(x, Staff_List, &f);
                    cont++;
                }
                x = x->next;
            }
            cout << "█████████████████████████████████████████████████████████████\n";
            cout << "██       EXCLUSÃO DE FUNCIONÁRIOS FEITA COM SUCESSO!       ██\n";
            cout << "█████████████████████████████████████████████████████████████\n\n";

            cout << "\n"
                 << cont << " funcionário(s) excluído(s) com sucesso!\n\n";

            cout << "\nDeseja voltar ao menu principal?[s/n]  ";
            cin >> choose;
            if (choose == 'n')
            {
                cout << "\nPrograma finalizado.";
                system("pause");
            }
            else
            {
                cout << "Voltando ao menu pricipal, aguarde";
                for (int i = 0; i < 7; i++)
                {
                    Sleep(300);
                    cout << ". ";
                    system("cls");
                }
            }
            break;

        default:
            cout << "Voltando ao menu pricipal, aguarde";
            for (int i = 0; i < 7; i++)
            {
                Sleep(300);
                cout << ". ";
                system("cls");
            }
        }
    } while (option != 1 && option != 2);
}

int foundLinkedList(tKey code, tLinked_list Staff_List, tPointer *p)
{
    tPointer aux = Staff_List.first;
    int achou = 0;

    while ((!achou) && (aux->next != NULL))
        if (aux->next->item.staff_code == code)
            achou = 1;
        else
            aux = aux->next;
    *p = aux;
    return (achou);
}

int projectResearch(tSequential_list Project_List, int code, int *q)
{
    int i = Project_List.first_project;
    int achou = 0;
    while (!achou && i < Project_List.last_project)
    {
        if (code == Project_List.item_project[i].project_code)
        {
            achou = 1;
        }
        i++;
    }
    *q = i;
    return achou;
}

void removeSequence(int p, tSequential_list *Project_List, tProject *q)
{
    int i;
    if (verifyEmptyLinearList(*Project_List) == 1)
    {
        cout << "Erro: Lista vazia ou posicao invalida \n ";
    }
    *q = Project_List->item_project[p];
    Project_List->last_project--;
    for (i = p; i < Project_List->last_project; i++)
    {
        Project_List->item_project[i] = Project_List->item_project[i + 1];
    }
}

void excludeProjects(tLinked_list *Staff_List, tSequential_list Project_List)
{
    tPointer p;
    tProject pj;
    int q, cod;
    int num, ret1, ret2;
    int indice;
    char choose;
    char x;

    cout << "████████████████████████████████████████████████████\n";
    cout << "██               EXCLUSÃO DE PROJETOS             ██\n";
    cout << "████████████████████████████████████████████████████\n\n";

    cout << "Informe o código do funcionário: ";
    cin >> cod;

    do
    {
        ret1 = staffResearch(cod, &p);

        if (ret1 == 1)
        {
            cout << "\nCódigo do Funcionário: " << p->next->item.staff_code;
            cout << "\nNome: " << p->next->item.name;
            cout << "\nEndereço: " << p->next->item.address;
            cout << "\nQuantidade de dependentes: " << p->next->item.num_dependents;
            cout << "\nNúmero de projetos que o funcionário está: " << p->next->item.num_projects << endl
                 << endl;
            for (int i = 0; i < p->next->item.num_projects; i++)
            {
                cout << "\nCódigo do Projeto: " << p->next->item.project.item_project->project_code;
                cout << "\nNome do Projeto: " << p->next->item.project.item_project->name_project;
                cout << "\nHoras trabalhadas neste projeto: " << p->next->item.project.item_project->hours << endl
                     << endl;
            }
            cout << "\n\nDeseja pesquisar por outro funcionário?[s/n]  ";
            cin >> choose;
            if (choose == 'n')
            {
                cout << "Voltando ao menu principal, aguarde";
                for (int i = 0; i < 7; i++)
                {
                    Sleep(300);
                    cout << ". ";
                    break;
                }
                system("cls");
            }

            ret2 = foundLinkedList(cod, *Staff_List, &p);

            if (ret2 == 1)
            {
                p = p->next;
                cout << "Informe o código do projeto: ";
                cin >> num;

                if (projectResearch(p->item.project, num, &q) == 1)
                {
                    removeSequence(q, &(p->item.project), &pj);

                    cout << "Projeto excluído com sucesso!\n\n";
                }
                else
                {
                    cout << "O projeto informado não está na lista";
                    Sleep(300);
                }

                cout << "Deseja excluir outro projeto?[s/n] ";
                cin >> choose;

                if (choose = 'n')
                {
                    cout << "\n\nDeseja voltar ao menu principal?[s/n]  ";
                    cin >> x;
                    if (choose == 'n')
                    {
                        cout << "\nPrograma finalizado.";
                        system("pause");
                    }
                    else
                    {
                        cout << "Voltando ao menu pricipal, aguarde";
                        for (int i = 0; i < 7; i++)
                        {
                            Sleep(300);
                            cout << ". ";
                            system("cls");
                        }
                    }
                }
            }
        }
    } while (choose != 'n');
}

int hours(tSequential_list Project_List)
{
    int total = 0;
    for (int i = 0; i < Project_List.last_project; i++)
    {
        total += Project_List.item_project[i].hours;
    }
    return total;
}

void printPaycheck(tLinked_list Staff_List)
{
    tPointer aux = Staff_List.first->next;
    char option;
    float hours_worked_week = 0, gross_salary = 0;
    float inss_discount = 0;
    float income_tax = 0;

    cout << "█████████████████████████████████████████████\n";
    cout << "██               CONTRA-CHEQUE             ██\n";
    cout << "█████████████████████████████████████████████\n\n";

    while (aux != NULL)
    {
        if (aux->item.num_projects != 0)
        {

            hours_worked_week = hours(aux->item.project);

            gross_salary = (45 * hours_worked_week) + (35 * aux->item.num_dependents);

            inss_discount = gross_salary * (8.5 / 100);

            income_tax = gross_salary * (15 / 100);

            cout << "███████████████████████████████████████████\n";
            cout << "██               FUNCIONÁRIO             ██\n";
            cout << "███████████████████████████████████████████\n\n";

            cout << "\nCódigo do Funcionário: " << aux->item.staff_code;
            cout << "\nNome: " << aux->item.name;
            cout << "\nNúmero de projetos que o funcionário está: " << aux->item.num_projects;
            cout << "\nHoras trabalhadas por semana: " << hours_worked_week;
            cout << "\nSalário bruto: " << gross_salary;
            cout << "\nDesconto do INSS de 8.5%: " << inss_discount;
            cout << "\nDesconto do imposto de renda de 15%: " << income_tax << endl
                 << endl;
        }
        aux = aux->next;
    }
    cout << "\n\nDeseja voltar ao menu principal?[s/n]  ";
    cin >> option;
    if (option == 'n')
    {
        cout << "\nPrograma finalizado.";
        system("pause");
    }
    else
    {
        cout << "Voltando ao menu pricipal, aguarde";
        for (int i = 0; i < 7; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("cls");
    }
}

void printList(tLinked_list *Staff_List)
{
    tPointer aux = Staff_List->first->next;

    while (aux != NULL)
    {
        cout << "\nCódigo do Funcionário: " << aux->item.staff_code;
        cout << "\nNome: " << aux->item.name;
        cout << "\nEndereço: " << aux->item.address;
        cout << "\nQuantidade de dependentes: " << aux->item.num_dependents;
        cout << "\nNúmero de projetos que o funcionário está: " << aux->item.num_projects << endl
             << endl;

        if (verifyEmptyLinearList(Project_List) != 1)
        {
            for (int i = 0; i <= aux->item.num_projects; i++)
            {
                cout << "\nProjeto de número: " << i;
                cout << "\nCódigo do Projeto: " << aux->item.project.item_project->project_code;
                cout << "\nNome do Projeto: " << aux->item.project.item_project->name_project;
                cout << "\nHoras trabalhadas neste projeto: " << aux->item.project.item_project->hours << endl
                     << endl;
            }
        }

        aux = aux->next;
    }
}

void getStaff()
{
    FILE *archive;
    tStaff f;
    tPointer p;
    archive = fopen("funcionarios.bin", "rb");
    p = Staff_List.first;

    if (archive != NULL)
    {
        while (fread(&f, sizeof(tStaff), 1, archive))
        {
            insertStaff(f, &Staff_List);
        }
        fclose(archive);
    }
    else
    {
        cout << "ARQUIVO INEXISTENTE!";
        system("pause");
        system("cls");
    }
}

void saveStaff()
{
    FILE *archive;
    tStaff f;
    tPointer p;
    archive = fopen("funcionarios.bin", "wb");
    p = Staff_List.first;

    while (p->next != NULL)
    {
        f = p->next->item;
        fwrite(&f, sizeof(tStaff), 1, archive);
        p = p->next;
    }
    fclose(archive);
}

void menu()
{
    int option;
    getStaff();
    do
    {
        system("cls");

        cout << " \n    ████████████████████████████████████████████████████████████\n";
        cout << "                         DEPARTAMENTO PESSOAL                    ";
        cout << " \n    ██                                                        ██";
        cout << " \n    ████████████████████████████████████████████████████████████\n";
        cout << " \n    ██             1 - Incluir novo funcionário               ██";
        cout << " \n    ██             2 - Incluir novos projetos                 ██";
        cout << " \n    ██             3 - Excluir Projetos                       ██";
        cout << " \n    ██             4 - Excluir funcionários                   ██";
        cout << " \n    ██             5 - Consultar funcionário                  ██";
        cout << " \n    ██             6 - Imprimir contra-cheque                 ██";
        cout << " \n    ██             7 - Sair                                   ██";
        cout << " \n    ████████████████████████████████████████████████████████████\n";

        cout << "\n Digite o numero referente a sua opçao: ";
        cin >> option;
        system("cls");

        switch (option)
        {
        case 1:
            registerStaff(&Staff_List, Project_List);
            break;

        case 2:
            includesProjects(&Staff_List);
            break;

        case 3:
            excludeProjects(&Staff_List, Project_List);
            break;

        case 4:
            excludeStaff(&Staff_List);
            break;

        case 5:
            staffConsultation(&Staff_List);
            break;
        case 6:
            printPaycheck(Staff_List);
            break;
        case 7:
            saveStaff();
            break;
        default:
            system("pause");
            break;
        }

    } while (option != 7);
}