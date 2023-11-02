#include <stdio.h>
#define MAX 5

struct queue
{
    int f;
    int b;
    int arr[MAX];
};

void enqueue(struct queue *q, int value)
{
    if (q->b == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->f = 0;
        q->b++;
        q->arr[q->b] = value;
    }
}

int dequeue(struct queue *q)
{
    if (q->f == -1)
    {
        printf("Queue if Empty\n");
    }
    else
    {
        if (q->f == q->b)
        {
            int temp = q->arr[q->f];
            q->f = -1;
            q->b = -1;
            return temp;
        }
        int temp = q->arr[q->f];
        q->f++;
        return temp;
    }
}

void display(struct queue q)
{
    for (int i = q.f; i <= q.b; i++)
    {
        printf("%d\n", q.arr[i]);
    }
}

void main()
{
    struct queue q;
    q.f = -1;
    q.b = -1;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    enqueue(&q,6);
    enqueue(&q,7);
    display(q);
}