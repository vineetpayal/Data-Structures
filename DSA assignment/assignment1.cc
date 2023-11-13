#include <stdio.h>
#include <string.h>
int precedence(char ch)
{
    switch (ch)
    {
    case '/':
    case '*':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
        return 4;
    default:
        return 0;
    }
}

int evaluate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}

void push(int stack[], int max, int value, int *top)
{
    if (*top == max - 1)
    {
        printf("Stack overflow!");
        return;
    }
    stack[++(*top)] = value;
}

int pop(int stack[], int *top)
{
    if (*top == -1)
        printf("stack is empty\n");
    else
        return stack[(*top)--];
}

int isEmpty(int top)
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char s[10];
    printf("Enter expression: ");
    scanf("%s",s);
    int maxLength = strlen(s);
    int opndTop = -1;
    int oprtrTop = -1;
    int opnd[maxLength];
    int oprtr[maxLength];

    for (int i = 0; i < maxLength; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int digit = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                digit = digit * 10 + (s[i] - 48);
                i++;
            }
            push(opnd, maxLength, digit, &opndTop);
            i--;
        }
        else if (s[i] == '(')
        {
            push(oprtr, maxLength, '(', &oprtrTop);
        }
        else if (s[i] == ')')
        {

            while (oprtr[oprtrTop] != '(')
            {
                int b = pop(opnd, &opndTop);

                int a = pop(opnd, &opndTop);

                char op = pop(oprtr, &oprtrTop);

                push(opnd, maxLength, evaluate(a, b, op), &opndTop);
            }
            pop(oprtr, &oprtrTop);
        }
        else
        {
            if (isEmpty(oprtrTop))
            {
                push(oprtr, maxLength, s[i], &oprtrTop);
                continue;
            }
            else if (precedence(s[i]) >= precedence(oprtr[oprtrTop]))
            {
                int b = pop(opnd, &opndTop);

                int a = pop(opnd, &opndTop);

                char op = pop(oprtr, &oprtrTop);

                push(opnd, maxLength, evaluate(a, b, op), &opndTop);
            }
            push(oprtr, maxLength, s[i], &oprtrTop);
        }
    }
    if (isEmpty(opndTop) && isEmpty(oprtrTop))
    {
        printf("Please enter a valid expression\n");
    }
    else if (isEmpty(oprtrTop) && !isEmpty(opndTop))
    {
        printf("Result: %d", pop(opnd, &opndTop));
    }
    else
    {
        int b = pop(opnd, &opndTop);
        int a = pop(opnd, &opndTop);
        char op = pop(oprtr, &oprtrTop);
        printf("Result: %d", evaluate(a, b, op));
    }
    return 0;
}