#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

node *top = NULL;

void push(int value)
{
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = value;

    if (top == NULL)
    {
        top = new_node;
        top->next = NULL;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
}

int pop()
{
    int value = -1;
    if (top == NULL)
    {
        printf("Stack Underflow");
    }
    else
    {
        value = top->data;
        if (top->next != NULL)
        {
            top = top->next;
        }
    }
    return value;
}

void display()
{
    node *temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    int result = pop();
    printf("After Popping:\n");
    display();
    printf("The value popped is: %d \n", result);
    printf("\nVineet Payal, A1(68)\n");
}