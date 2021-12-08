#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template <typename T>
struct Node;

template <typename T>
struct LinkedList;

template <typename T>
LinkedList<T> *create();

template <typename T>
void insertItem(T e, LinkedList<T> *list);

template <typename T>
bool isEmpty(LinkedList<T> *list);

template <typename T>
Node<T> *searchItem(LinkedList<T> *list, int val, bool (*compare)(T, int));

template <typename T>
void printList(LinkedList<T> *list, void (*print)(T));

template <typename T>
bool deleteItem(LinkedList<T> *list, Node<T> *&node);

#include "linkedlist.cpp"
#endif