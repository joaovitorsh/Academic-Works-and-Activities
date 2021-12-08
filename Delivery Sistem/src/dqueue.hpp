#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
struct NodeDQueue;

template <typename T>
struct DQueue;

template <typename T>
DQueue<T> *createDQueue();

template <typename T>
bool isEmptyDQueue(DQueue<T> *queue);

template <typename T>
bool enqueueDQueue(DQueue<T> *queue, T item);

template <typename T>
bool dequeueDQueue(DQueue<T> *queue, T *item);

template <typename T>
bool peekDQueue(DQueue<T> *queue, T *item);

template <typename T>
void printDQueue(DQueue<T> *queue, void (*print)(T));

template <typename T>
void emptyDQueue(DQueue<T> *queue);

#include "dqueue.cpp"
#endif