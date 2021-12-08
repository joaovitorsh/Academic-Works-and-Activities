#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
struct Queue;

template <typename T>
Queue<T> *createQ(int maxSize);

template <typename T>
bool isEmpty(Queue<T> *queue);

template <typename T>
bool isFull(Queue<T> *queue);

template <typename T>
bool enqueue(Queue<T> *queue, T item);

template <typename T>
bool dequeue(Queue<T> *queue, T *item);

template <typename T>
void printQueue(Queue<T> *queue, void (*print)(T));

#include "queue.cpp"
#endif