template <typename T>
struct NodeDQueue
{
    T item;
    NodeDQueue<T> *next = NULL; 
};

template <typename T>
struct DQueue
{
    NodeDQueue<T> *front = NULL;
    NodeDQueue<T> *rear = NULL;
    int size;
};

template <typename T>
DQueue<T> *createDQueue()
{
    DQueue<T> *q = new DQueue<T>;
    q->size = 0;
    return q;
}

template <typename T>
bool isEmptyDQueue(DQueue<T> *queue)
{
    return (queue->size == 0);
}

template <typename T>
bool enqueueDQueue(DQueue<T> *queue, T item)
{
    NodeDQueue<T> *aux = new NodeDQueue<T>;
    aux->item = item;
    if (queue->front == NULL)
    {
        queue->front = aux;
        queue->rear = aux;
        queue->size++;
        return true;
    }
    queue->rear->next = aux;
    queue->rear = queue->rear->next;
    queue->size++;
    return true;
}

template <typename T>
bool dequeueDQueue(DQueue<T> *queue, T *item)
{
    if (queue == NULL)
    {
        return false;
    }
    if (isEmptyDQueue(queue))
    {
        return false;
    }
    *item = queue->front->item;
    queue->front = queue->front->next;
    queue->size--;
    if(queue->size == 0){
        queue->rear = NULL;
    }

    return true;
}

template <typename T>
bool peekDQueue(DQueue<T> *queue, T *item)
{
    if (queue == NULL)
    {
        return false;
    }
    if (isEmptyDQueue(queue))
    {
        return false;
    }
    *item = queue->front->item;
    return true;
}

template <typename T>
void printDQueue(DQueue<T> *queue, void (*print)(T))
{
    NodeDQueue<T> *it = queue->front;
    while (it != NULL)
    {
        print(it->item);
        it = it->next;
    }
}

template <typename T>
void emptyDQueue(DQueue<T> *queue)
{
    T *aux = new int;
    while (dequeueDQueue(queue, aux) && aux != NULL);
}