#include <stdio.h>
#include <stdlib.h>
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
        char value = stack[*top];
        (*top)--;
        return value;
    }
}

int prec(char op)
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

void display(char stack[], int top)
{
    while (top != -1)
    {
        printf("%c\n", stack[top]);
        top--;
    }
}

void rev(char *s, int l)
{
    char temp;
    for (int i = 0; i < l / 2; i++)
    {
        temp = *(s + i);
        *(s + i) = *(s + l - i - 1);
        *(s + l - i - 1) = temp;
    }
}

void main()
{
    char stack[MAX];
    int top = -1;

    char s[] = "a+b/c-d*e";
    int l = strlen(s);
    rev(s, l);
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
            char op = s[i];

            while (top != -1 && (prec(stack[top]) >= prec(op)))
            {
                ans[j++] = pop(stack, &top);
            }

            push(stack, &top, op);
        }
    }
    while (top != -1)
    {
        ans[j++] = pop(stack, &top);
    }
    ans[j] = '\0';
    rev(ans, l);
    printf("Answer: %s\n", ans);
    display(stack, top);
}