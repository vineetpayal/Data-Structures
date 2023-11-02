#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

void enqueue(node **f, node **b, int value)
{
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;

    if (*f == NULL)
    {
        *f = new_node;
        *b = new_node;
    }
    else
    {
        (*b)->next = new_node;
        *b = new_node;
    }
}

int dequeue(node **f, node **b)
{
    int value = -1;
    if (*f == NULL)
    {
        printf("Queue is empty\n");
    }
    else if (*f == *b)
    {
        value = (*f)->data;
        *f = NULL;
        *b = NULL;
    }
    else
    {
        value = (*f)->data;
        (*f) = (*f)->next;
    }

    return value;
}

void display(node **f, node **b)
{
    if (*f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        node *temp = *f;

        while (temp != *b)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d \n", temp->data);
    }
}

void main()
{
    node *front = NULL;
    node *back = NULL;

    enqueue(&front, &back, 1);
    enqueue(&front, &back, 2);
    enqueue(&front, &back, 3);
    enqueue(&front, &back, 4);
    enqueue(&front, &back, 5);
    display(&front, &back);

    int result = dequeue(&front, &back);
    printf("After dequeue: \n");
    display(&front, &back);
    printf("The dequeued element is: %d\n", result);
    printf("\nVineet Payal, A1(68)\n");
}