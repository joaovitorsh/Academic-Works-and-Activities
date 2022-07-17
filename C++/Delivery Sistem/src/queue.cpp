template <typename T>
struct Queue
{
    T *itens; // This is an array
    int maxSize;
    int front; // Index of the queue's front
    int rear;  // Index of the queue's rear
    int size;
};

template <typename T>
Queue<T> *createQ(int maxSize)
{
    Queue<T> *q = new Queue<T>;
    q->itens = new T[maxSize];
    q->maxSize = maxSize;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

template <typename T>
bool isEmpty(Queue<T> *queue)
{
    return (queue->front == -1);
}

template <typename T>
bool isFull(Queue<T> *queue)
{
    return (queue->size == queue->maxSize);
}

template <typename T>
bool enqueue(Queue<T> *queue, T item)
{
    if (isFull(queue))
    {
        return false;
    }

    if (queue->rear == (queue->maxSize - 1))
    {
        queue->rear = 0;
    }
    else
    {
        queue->rear++;
    }
    queue->itens[queue->rear] = item;
    queue->size++;
    return true;
}

template <typename T>
bool dequeue(Queue<T> *queue, T *item)
{
    if (queue == NULL)
    {
        return false;
    }
    if (isEmpty(queue))
    {
        return false;
    }
    *item = queue->itens[queue->front];
    if (queue->front == (queue->maxSize - 1))
    {
        queue->front = 0;
    }
    else
    {
        queue->front++;
    }
    queue->size--;
    return true;
}

// template <typename T>
// bool peek(Stack<T> *stack, T *item)
// {
//     if (stack == NULL)
//     {
//         return false;
//     }
//     if (isEmpty(stack))
//     {
//         return false;
//     }
//     *item = stack->itens[stack->top]; // Return the last item e remove it
//     return true;
// }

template <typename T>
void printQueue(Queue<T> *queue, void (*print)(T))
{
    int i = queue->front;
    do
    {
        print(queue->itens[i]);
        if (i == (queue->maxSize - 1))
        {
            i = 0;
        }
        else
        {
            i++;
        }
    } while (i != queue->front && i != queue->rear + 1);
}