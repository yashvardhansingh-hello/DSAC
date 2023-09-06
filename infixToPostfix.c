#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        (ptr->top)--;
        return val;
    }
}

void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow");
    }
    else
    {
        (ptr->top)++;
        ptr->arr[ptr->top] = value;
    }
}

char stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int isOperator(char c)
{
    if (c == '*' || c == '+' || c == '/' || c == '-')
        return 1;
    else
        return 0;
}

int precedence(char c)
{
    if (c == '*' || c == '/')
    {
        return 3;
    }
    else
    {
        if (c == '-' || c == '+')
            return 2;
        else
            return 0;
    }
}

char *infixToPost(char *infix)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (char *)malloc(sizeof(char) * s->size);
    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    postfix[j] = '\0';
    while (!isEmpty(s))
    {
        postfix[j++] = pop(s);
    }
    return postfix;
}

int main()
{
    char *infix = "";
    scanf("%s", &infix);

    printf("%s\n", infix);
    printf("%s\n", infixToPost(infix));
    return 0;
}