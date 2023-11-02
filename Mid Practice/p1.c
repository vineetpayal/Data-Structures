#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev, *next;
};
typedef struct node node;

void insert(node **head, node **tail, int value)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = value;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        newNode->next = NULL;
        *tail = newNode;
    }
}

void display(node *head, node *tail)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAfter(node **head, node **tail, int after, int value)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = value;

    if ((*tail)->data == after)
    {
        newNode->next = NULL;
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
    else
    {
        node *temp = *head;
        while (temp != NULL)
        {
            if (temp->data == after)
            {
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
    }
}

void delete(node **head, node **tail, int value)
{
    if ((*head)->data == value)
    {
        (*head) = (*head)->next;
        (*head)->prev = NULL;
    }
    else if ((*tail)->data == value)
    {
        (*tail) = (*tail)->prev;
        (*tail)->next = NULL;
    }
    else
    {
        node *temp = *head;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                break;
            }
            temp = temp->next;
        }
    }
}

void main()
{
    node *head = NULL;
    node *tail = NULL;
    insert(&head, &tail, 1);
    insert(&head, &tail, 2);
    insert(&head, &tail, 3);
    insertAfter(&head, &tail, 3, 44);
    delete(&head,&tail,2);
    display(head, tail);
}