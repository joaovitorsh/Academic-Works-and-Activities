template <typename T>
struct NodeDStack
{
    T item;
    NodeDStack<T> *next = NULL;
};

template <typename T>
struct DStack
{
    NodeDStack<T> *top = NULL;
    int size = 0;
};

template <typename T>
DStack<T> *createDStack()
{
    DStack<T> *s = new DStack<T>;
    // s->itens = new T[maxSize];
    // s->maxSize = maxSize;
    // s->top = -1;
    return s;
}

template <typename T>
bool isEmptyDStack(DStack<T> *stack)
{
    return (stack->size == 0);
}

template <typename T>
bool pushDStack(DStack<T> *stack, T item)
{
    NodeDStack<T> *node = new NodeDStack<T>;
    node->item = item;

    if (isEmptyDStack(stack))
    {
        stack->top = node;
        stack->size++;
        return true;
    }

    node->next = stack->top;
    stack->top = node;
    stack->size++;

    return true;
}

template <typename T>
bool popDStack(DStack<T> *stack, T *item)
{
    if (stack == NULL)
    {
        return false;
    }
    if (isEmptyDStack(stack))
    {
        return false;
    }
    *item = stack->top->item; // Return the last item e remove it
    stack->top = stack->top->next;
    stack->size--;
    return true;
}

template <typename T>
bool peekDStack(DStack<T> *stack, T *item)
{
    if (stack == NULL)
    {
        return false;
    }
    if (isEmptyDStack(stack))
    {
        return false;
    }
    *item = stack->top->item; // Return the last item e remove it
    return true;
}

template <typename T>
void printDStack(DStack<T> *stack, void (*print)(T))
{
    for(NodeDStack<T> *aux = stack->top; aux != NULL; aux = aux->next){
        print(aux->item);
    }
}