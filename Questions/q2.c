/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Input: head = [1,2,2,1]
Output: true
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

int isPalindrome(node *head)
{
    int flag = 1;
    node *rev = reverse(head);

    node *t1 = head;
    node *t2 = rev;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data != t2->data)
        {
            flag = 0;
            break;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    if (t1 != t1)
    {
        flag = 0;
    }
    return flag;
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
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    display(head);

    if (isPalindrome(head))
    {
        printf("\nList is palindrome\n");
    }
    else
    {
        printf("\nList is not palindrome\n");
    }
}