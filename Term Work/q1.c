/*
Write a C program to Insert and Delete elements form a Queue using link list ,each node
should have the following inforamaion about a product Product_Id(char) , Product_Name(string) ,
Total_sale(integer),Product_Grade(Char
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char Product_Id;
    char Product_Name[50];
    int Total_sale;
    char Product_Grade;
    struct node *next;
};
typedef struct node node;

node *createNode()
{
    node *newNode = (node *)malloc(sizeof(node));

    printf("Product Name: ");
    scanf("%s", newNode->Product_Name);
    fflush(stdin);

    printf("Product Id: ");
    scanf("%c", &newNode->Product_Id);

    printf("Total sale: ");
    scanf("%d", &newNode->Total_sale);
    fflush(stdin);

    printf("Product Grade: ");
    scanf("%c", &newNode->Product_Grade);
    newNode->next = NULL;
    return newNode;
}

void enqueue(node **f, node **b, node *newNode)
{
    if (*f == NULL)
    {
        *f = newNode;
        *b = newNode;
    }
    else
    {
        (*b)->next = newNode;
    }
}

node *dequeue(node **f, node **b)
{
    node *result = NULL;
    if (*f == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else if (*f == *b)
    {
        *f = NULL;
        *b = NULL;
    }
    else
    {
        result = *f;
        *f = (*f)->next;
    }
    return result;
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
            printf("Product Name: %s\nProduct Id: %c\nTotal Sale: %d\nProduct Grade: %c\n",
                   temp->Product_Name, temp->Product_Id, temp->Total_sale, temp->Product_Grade);
            temp = temp->next;
        }
        printf("Product Name: %s\nProduct Id: %c\nTotal Sale: %d\nProduct Grade: %c\n",
               temp->Product_Name, temp->Product_Id, temp->Total_sale, temp->Product_Grade);
    }
}

void main()
{
    node *f = NULL, *b = NULL;
    int choice;
    while (1)
    {
        printf("\nInstructions: \n");
        printf("Press 1 for inserting\nPress 2 for deleting\nPress 3 for display\nPress 4 to exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:;
            node *newNode = createNode();
            enqueue(&f, &b, newNode);
            break;
        case 2:;
            node *deleted = dequeue(&f, &b);
            printf("Product with id: %c deleted", deleted->Product_Id);
            free(deleted);
            break;
        case 3:
            printf("\n\tDETAILS:\n");
            display(&f, &b);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid instruction!");
        }
    }
}