#include <stdio.h>
#include <string.h>
#define MAX 50

void push(char stack[], int *top, char value)
{
    if (*top == MAX - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        stack[++(*top)] = value;
    }
}

char pop(char stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        return stack[(*top)--];
    }
}

void display(char stack[], int top)
{
    for (int i = top; i >= 0; i--)
    {
        printf("%c\n", stack[i]);
    }
}

int precendence(char op)
{
    switch (op)
    {
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void main()
{
    int top = -1;
    char stack[MAX];
    char s[] = "a+b/c-d*e";
    int l = strlen(s);
    char ans[l];
    int j = 0;

    for (int i = 0; i < l; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans[j++] = s[i];
        }
        else
        {
            if (top != -1 && precendence(s[i]) < precendence(stack[top]))
            {
                char op = pop(stack, &top);
                ans[j++] = op;
            }
            push(stack, &top,  s[i]);
        }
    }

    printf("Answer: %s", ans);
}