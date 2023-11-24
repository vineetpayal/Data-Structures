/*
Q2. Let A and B be two structures of type Linked List. Write a ‘C ’ program to create a new
Linked List ‘S’ that contains elements alternately from A and B beginning with the first
element of A. If you run out of elements in one of the lists, then append the remaining
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

void insertAtEnd(node **head, int value)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

node *alternateMerge(node *A, node *B)
{
    node *result = NULL;
    while (A != NULL || B != NULL)
    {
        if (A != NULL)
        {
            insertAtEnd(&result, A->data);
            A = A->next;
        }

        if (B != NULL)
        {
            insertAtEnd(&result, B->data);
            B = B->next;
        }
    }
    return result;
}

void display(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void main()
{
    node *A = NULL;
    node *B = NULL;
    node *R = NULL; // result
    int choice, num;

    while (1)
    {
        printf("\n\tInstructions:\n");
        printf("Press 1 to insert in A\nPress 2 to insert in B\nPress 3 to display result:\nPress 4 to exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter A: ");
            scanf("%d", &num);
            insertAtEnd(&A, num);
            break;
        case 2:
            printf("Enter B: ");
            scanf("%d", &num);
            insertAtEnd(&B, num);
            break;

        case 3:
            R = alternateMerge(A, B);
            display(R);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Instruction");
            break;
        }
    }
}