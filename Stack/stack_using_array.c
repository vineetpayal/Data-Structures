#include <stdio.h>
#define MAX 50

void push(int stack[], int *top, int value)
{
    if (*top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        (*top)++;
        stack[*top] = value;
    }
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        int value = stack[*top];
        (*top)--;
        return value;
    }
}

void displayStack(int stack[], int top)
{
    if (top == -1)
    {
        printf("Nothing to display\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

void main()
{
    int stack[MAX];
    int top = -1;

    push(stack,&top,1);
    push(stack,&top,2);
    push(stack,&top,3);
    push(stack,&top,4);
    push(stack,&top,5);

    printf("Before popping:\n");
    displayStack(stack,top);

    int result = pop(stack,&top);
    printf("After popping:\n");
    displayStack(stack,top);
    printf("The popped value is: %d\n",result);
    printf("\nVineet Payal, A1(68)\n");
    
}