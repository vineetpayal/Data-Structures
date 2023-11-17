/*
Given head which is a reference node to a singly linked list. The value of each node in the
linked list is either 0 or 1. The linked list holds the binary representaKon of a number. Return
the decimal value of the number in the linked list.
Ex: Input= [1,0,1]
Output= 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

void insert(node **head, int value)
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

node *reverse(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;
    node *reverseList = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    reverseList = prev;

    return reverseList;
}

int binaryToDecimal(node *head)
{
    node *rev = reverse(head);
    node *temp = rev;
    int num = 0;

    for (int i = 0; temp != NULL; i++)
    {
        num = num + (temp->data) * (pow(2, i));
        temp = temp->next;
    }

    return num;
}

void main()
{
    node *head = NULL;
    insert(&head, 1);
    insert(&head, 0);
    insert(&head, 1);
    display(head);
    int result = binaryToDecimal(head);
    printf("Decimal Equivalent:%d\n", result);
}