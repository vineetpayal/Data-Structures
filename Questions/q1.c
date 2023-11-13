/*
Given a singly linked list and a key, count the number of occurrences of the given key in the
linked list. For example, if the given linked list is 1->2->1->2->1->3->1 and the given key is 1,
then the output should be 4.
*/
#include <stdio.h>
#include <stdlib.h>

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

int count(node *head, int key)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
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
    node *head = NULL;
    int key;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 1);
    display(head);

    printf("\nEnter key: ");
    scanf("%d", &key);
    printf("\nThe count of %d is %d\n", key, count(head, key));
}