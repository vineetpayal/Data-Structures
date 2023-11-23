/*
Given two numbers represented by two lists, write a funcKon that returns the sum in the
form of a linked list.
Input:
List1: 5->6->3 // represents number 563
List2: 8->4->2 // represents number 842
Output:
Resultant list: 1->4->0->5 // represents number 1405
ExplanaKon: 563 + 842 = 1405
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

node *rev(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int toInt(node *head)
{
    node *temp = head;
    int num = 0;
    while (temp != NULL)
    {
        num = num * 10 + temp->data;
        temp = temp->next;
    }
    return num;
}

node *toLinkedList(int num)
{
    node *list = NULL;
    while (num != 0)
    {
        insert(&list, num % 10);
        num = num / 10;
    }
    return list;
}

node *add(node *n1, node *n2)
{
    int num1 = toInt(n1);
    int num2 = toInt(n2);
    int sum = num1 + num2;
    return rev(toLinkedList(sum));
}

void display(node *head)
{
    while (head->next != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("%d\n", head->data);
}

void main()
{
    node *n1 = NULL;
    node *n2 = NULL;

    insert(&n1, 2);
    insert(&n1, 9);
    insert(&n1, 1);

    insert(&n2, 1);
    insert(&n2, 2);
    insert(&n2, 3);
    insert(&n2, 4);

    node *sum = add(n1, n2);
    display(sum);
}