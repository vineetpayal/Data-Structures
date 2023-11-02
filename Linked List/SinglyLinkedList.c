#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;

void Insert(int data)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Going to the last node
        // storing address of head in temp variable to go to last element without changing the head pointer
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void update(int oldvalue, int newValue)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == oldvalue)
        {
            temp->data = newValue;
        }
        temp = temp->next;
    }
}

void delete(int value)
{
    node *temp = head;
    node *tempAdd;
    while (temp->next != NULL)
    {
        if (temp->next->data == value)
        {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

void displayLinkedList()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

void reverse()
{
    node *prev = NULL;
    node *curr = head;
    node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void main()
{
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Insert(6);
    displayLinkedList();
    reverse();
    printf("\n");
    displayLinkedList();
}