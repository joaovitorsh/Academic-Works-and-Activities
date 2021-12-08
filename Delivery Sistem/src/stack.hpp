#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
struct Stack;

template <typename T>
Stack<T> *createS(int maxSize);

template <typename T>
bool isEmpty(Stack<T> *stack);

template <typename T>
bool push(Stack<T> *stack, T item);

template <typename T>
bool pop(Stack<T> *stack, T *item);

template <typename T>
bool peek(Stack<T> *stack, T *item);

template <typename T>
void printStack(Stack<T> *stack, void (*print)(T));

template <typename T>
int size(Stack<T> *stack);

#include "stack.cpp"
#endif