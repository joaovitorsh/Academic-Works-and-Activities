#ifndef DSTACK_HPP
#define DSTACK_HPP

template <typename T>
struct DStack;

template <typename T>
DStack<T> *createDStack();

template <typename T>
bool isEmptyDStack(DStack<T> *stack);

template <typename T>
bool pushDStack(DStack<T> *stack, T item);

template <typename T>
bool popDStack(DStack<T> *stack, T *item);

template <typename T>
bool peekDStack(DStack<T> *stack, T *item);

template <typename T>
void printDStack(DStack<T> *stack, void (*print)(T));

#include "dstack.cpp"
#endif