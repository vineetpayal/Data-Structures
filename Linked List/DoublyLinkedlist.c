#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
};
typedef struct node node;

node *createNode()
{
    return (node *)malloc(sizeof(node));
}

void insertAtLast(node **head, node **tail, int value)
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
        newNode->next = NULL;
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void insertAtBeg(node **head, node **tail, int value)
{
    node *newNode = createNode();
    newNode->data = value;
    newNode->prev = NULL;
    if (*head == NULL)
    {
        newNode->next = NULL;
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void delete(node **head, node **tail, int value)
{

    if ((*head)->data == value)
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    else if ((*tail)->data == value)
    {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }
    else
    {
        node *temp = *head;
        while (temp->data != value)
        {
            if (temp == NULL)
            {
                printf("No search found.");
                break;
            }
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
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

void main()
{
    node *head = NULL, *tail = NULL;

    // insert at last
    insertAtLast(&head, &tail, 1);
    insertAtLast(&head, &tail, 2);
    insertAtLast(&head, &tail, 3);
    insertAtLast(&head, &tail, 4);
    insertAtLast(&head, &tail, 5);

    // insert at begining
    insertAtBeg(&head, &tail, 6);
    insertAtBeg(&head, &tail, 7);
    insertAtBeg(&head, &tail, 8);
    insertAtBeg(&head, &tail, 9);
    insertAtBeg(&head, &tail, 10);

    // Prining the list
    display(head);

    // deleting a specific node
    delete (&head, &tail, 1);
    display(head);

    delete (&head, &tail, 10);
    display(head);

    delete (&head, &tail, 5);
    display(head);
}