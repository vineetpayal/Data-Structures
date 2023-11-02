#include <stdio.h>
#define MAX 100
int s1[MAX], s2[MAX];
int t1 = -1, t2 = -1;

void push(int stack[], int *top, int value)
{
    if (*top == MAX - 1)
    {
        printf("Queue is Full");
    }
    else
    {
        stack[++(*top)] = value;
    }
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        return stack[(*top)--];
    }
}

void enqueue(int value)
{
    push(s1, &t1, value);
}

int dequeue()
{
    if (t1 == -1)
    {
        return -1;
    }
    else
    {
        while (t1 != -1)
        {
            push(s2, &t2, pop(s1, &t1));
        }

        int result = pop(s2, &t2);

        while (t2 != -1)
        {
            push(s1, &t1, pop(s2, &t2));
        }

        return result;
    }
}

void display()
{
    for (int i = 0; i <= t1; i++)
    {
        printf("%d ", s1[i]);
    }
}

void main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printf("\nBefore Dequeue: ");
    display();

    int r = dequeue();
    printf("\nAfter dequeue: ");
    display();
    printf("\nDeleted element: %d\n", r);
}