#ifndef FUNCTION_H
#define FUNCTION_H

#define MAXTAM 5

typedef int tKey; //...

typedef struct tCell_Str *tPointer; //...

typedef struct
{
    tKey project_code;     // project code
    char name_project[30]; // project name
    float hours;           // number of hours worked per week on the project
} tProject;                // struct that stores project data

typedef struct
{
    tProject item_project[MAXTAM]; 
    int first_project;
    int last_project;
    int size_project;
} tSequential_list;

typedef struct
{
    tKey staff_code;          // employee code (there are no employees with the same code)
    char name[40];            
    char address[60];         
    int num_dependents;       
    int num_projects = 0;     // number of projects that the employee is in (limit up to 5 projects)
    tSequential_list project; // { "Project 1", "Project 2", ... }

} tStaff; // struct that stores the employee data

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

void createLinkedList(tLinked_list *Staff_List); // Creates the empty employee chained list

int checksEmptyLinkedList(tLinked_list Staff_List); // checks the list if it is empty or full

void createLinearList(tSequential_list &Project_List); // creates the empty project row
int verifyEmptyLinearList(tSequential_list &Project_List); // checks whether the list is empty or full

void insertStaff(tStaff f, tLinked_list *Staff_List); // Enters employee

void insertProject(tProject p, tSequential_list &Project_List); // Insert Project

void registerStaff(tLinked_list *Staff_List, tSequential_list Project_List); // Registers the employee and his projects

int staffResearch(tKey code, tPointer *p); // Function that searches for the employee and returns to the employee query function

void staffConsultation(tLinked_list *Staff_List); // Employee consultation

void deleteStaff(tPointer p, tLinked_list *Staff_List, tStaff *e); // Function that deletes the employee and returns to the employee exclusion function

void excludeStaff(tLinked_list *Staff_List); // Excludes employee

void includesProjects(tLinked_list *Staff_List); // Includes projects to an employee

int projectResearch(tSequential_list Project_List, int code, int *p);

void printPaycheck(tLinked_list Staff_List); // Prints employees' paychecks

void excludeProjects(tLinked_list *Staff_List, tSequential_list Project_List); // Excludes projects

void printList(tLinked_list *Staff_List); // function to print the employee list

void getStaff(); // Usada para chamar os dados do arquivo ao iniciar o programa

void saveStaff(); // Function for saving the data to file

int hours(tSequential_list Project_List); // Returns the total hours worked per week by the employee

void removeSequence(int p, tSequential_list *Project_List, tProject *q); // Removes the project from the project sequence

int foundLinkedList(tKey code, tLinked_list Staff_List, tPointer *p); // Finds an item within the chained list

void menu(); // Project menu

tSequential_list Project_List;
tLinked_list Staff_List;

#include "Functions.cpp"
#endif