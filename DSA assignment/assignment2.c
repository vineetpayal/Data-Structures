#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int a;
    int power;
    struct node *next;
};
typedef struct node node;

void insert(node **head, int a, int power)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->a = a;
    newNode->power = power;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(node **head)
{
    node *temp = *head;
    while (temp->next != NULL)
    {

        printf("%dx%d+", temp->a, temp->power);
        temp = temp->next;
    }
    printf("%dx%d", temp->a, temp->power);
}

void insertEquation(node **head, char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'x' && i == 0)
        {
            insert(head, 1, s[i + 1] - '0');
        }
        else if (s[i] == 'x' && i > 0)
        {
            insert(head, s[i - 1] - '0', s[i + 1] - '0');
        }
    }
}

void AddTwoEquation(node **p1, node **p2, node **r)
{
    node *temp1 = *p1;
    node *temp2 = *p2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->power == temp2->power)
        {
            int newCoeff = temp1->a + temp2->a;
            insert(r, newCoeff, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->power > 0)
        {
            insert(r, temp1->a, temp1->power);
            temp1 = temp1->next;
        }
        else if (temp2->power > 0)
        {
            insert(r, temp2->a, temp2->power);
            temp2 = temp2->next;
        }
        else
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
}

void main()
{
    node *p1 = NULL;
    node *p2 = NULL;
    node *r = NULL;
    char s1[50];
    char s2[50];

    // Inserting first equation
    printf("Enter P1: ");
    gets(s1);
    printf("Enter P2: ");
    gets(s2);
    insertEquation(&p1, s1);
    insertEquation(&p2, s2);

    // Adding two equation
    AddTwoEquation(&p1, &p2, &r);

    // Printing resultant equation
    printf("RESULT: ");
    display(&r);
}