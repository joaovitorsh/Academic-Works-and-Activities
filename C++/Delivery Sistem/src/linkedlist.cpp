#include <iostream>
template <typename T>
struct Node
{
    T data;
    Node<T> *next = NULL;
};

template <typename T>
struct LinkedList
{
    Node<T> *head = NULL;
    Node<T> *last = NULL;
};

template <typename T>
LinkedList<T> *create()
{
    LinkedList<T> *list = new LinkedList<T>;
    return list;
}

template <typename T>
void insertItem(T e, LinkedList<T> *list)
{
    if (list->head == NULL)
    {
        list->head = new Node<T>; 
        list->last = list->head;
        list->head->next = NULL;
        list->last->data = e;
        return;
    }
    list->last->next = new Node<T>;
    list->last = list->last->next;
    list->last->next = NULL;
    list->last->data = e;
}

template <typename T>
bool isEmptyL(LinkedList<T> *list)
{
    return (list->head == NULL);
}

template <typename T>
Node<T> *searchItem(LinkedList<T> *list, int val, bool (*compare)(T, int))
{
    if (isEmptyL(list))
    {
        return NULL;
    }
    Node<T> *current = list->head;

    do
    {
        if (compare(current->data, val))
        {
            return current;
        }
        current = current->next;
    } while (current != NULL);
    return NULL;
}

template <typename T>
void printList(LinkedList<T> *list, void (*print)(T))
{
    Node<T> *current = list->head;
    while (current != NULL)
    {
        print(current->data);
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool deleteItem(LinkedList<T> *list, Node<T> *&node)
{
    if (node == NULL)
    {
        return false;
    }
    if (node == list->head)
    {
        list->head = node->next;
        if (node->next == NULL)
        {
            list->last = list->head;
        }
    }
    else
    {
        Node<T> *prev = list->head;
        while (prev->next != node)
        {
            prev = prev->next;
        }
        prev->next = node->next;
        if (node->next == NULL)
        {
            list->last = prev;
        }
    }
    delete node; 
    return true;
}