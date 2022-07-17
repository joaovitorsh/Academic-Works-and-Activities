template <typename T>
struct Stack
{
    T *itens; // This is an array
    int maxSize;
    int top; // The index of last item inserted
};

template <typename T>
Stack<T> *createS(int maxSize)
{
    Stack<T> *s = new Stack<T>;
    s->itens = new T[maxSize];
    s->maxSize = maxSize;
    s->top = -1;
    return s;
}

template <typename T>
bool isEmpty(Stack<T> *stack)
{
    return (stack->top == -1);
}

template <typename T>
bool push(Stack<T> *stack, T item)
{
    if (stack->maxSize == (stack->top + 1))
    {
        return false;
    }
    stack->itens[++stack->top] = item;
    return true;
}

template <typename T>
bool pop(Stack<T> *stack, T *item)
{
    if (stack == NULL)
    {
        return false;
    }
    if (isEmpty(stack))
    {
        return false;
    }
    *item = stack->itens[stack->top--]; // Return the last item e remove it
    return true;
}

template <typename T>
bool peek(Stack<T> *stack, T *item)
{
    if (stack == NULL)
    {
        return false;
    }
    if (isEmpty(stack))
    {
        return false;
    }
    *item = stack->itens[stack->top]; // Return the last item only
    return true;
}

template <typename T>
void printStack(Stack<T> *stack, void (*print)(T))
{
    for (int i = stack->top; i >= 0; i--)
    {
        print(stack->itens[i]);
    }
}

template <typename T>
int size(Stack<T> *stack)
{
    return (stack->top + 1);
}