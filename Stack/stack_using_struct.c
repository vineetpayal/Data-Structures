#include <stdio.h>
#define MAX 20
struct stack
{
    int top;
    int arr[MAX];
};

void push(struct stack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overlflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        int value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display(struct stack s)
{
    for (int i = MAX - 1; i > 0; i--)
    {
        printf("%d\n", s.arr[i]);
    }
}

int isBalanced(struct stack *s, char input[])
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '(')
        {
            push(s, '(');
        }
        else if (input[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            pop(s);
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    struct stack s;
    s.top = -1;

    // Balance parenthesis
    char input[20] = ")(";
    if (isBalanced(&s, input))
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not balanced\n");
    }
}