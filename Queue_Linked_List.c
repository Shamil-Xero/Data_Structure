#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Queue *queue;

void InitializeQ(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void Enqueue(Queue *q, int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;

    if (q->front == NULL)
    {
        q->front = new;
        q->rear = new;
    }
    else
    {
        q->rear->next = new;
        q->rear = new;
    }
}

int Dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int data = q->front->data;
        Node *temp = q->front;
        q->front = q->front->next;

        if (q->front == NULL)
        {
            q->rear = NULL;
        }

        free(temp);
        return data;
    }
}

void DisplayQ(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        Node *temp = q->front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main()
{
    InitializeQ(&queue);
    do
    {
        printf("\n1. Display\n2. Enqueue\n3. Dequeue\n0. Exit\n");
        printf("Your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            DisplayQ(&queue);
            break;
        case 2:
            printf("Enter the data: ");
            int data;
            scanf("%d", &data);
            Enqueue(&queue, data);
            break;
        case 3:
            printf("Dequeued element: %d\n", Dequeue(&queue));
            break;
        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}