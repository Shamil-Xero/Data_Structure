#include <stdio.h>
#include <stdbool.h>

#define MAX 5

struct Queue
{
    int data[MAX];
    int front, rear;
};

// Initialize an empty circular queue
// struct Queue *queue;
// queue->front = queue->rear = -1;
void initQueue(struct Queue* queue) {
    queue->front = queue->rear = -1;
}

// Check if the queue is empty
bool isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

// Check if the queue is full
bool isFull(struct Queue *queue)
{
    return (queue->rear + 1) % MAX == queue->front;
}

// Enqueue (add customer)
void enqueue(struct Queue *queue, int customer_no)
{
    if (isFull(queue))
    {
        printf("Queue is full. Customer %d has to wait.\n", customer_no);
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = customer_no;
}

// Dequeue (serve customer)
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. No customer to serve.\n");
        return -1; // Return a sentinel value
    }
    int servedCustomer = queue->data[queue->front];
    if (queue->front == queue->rear)
        initQueue(queue); // Reset queue when last customer is served
    else
        queue->front = (queue->front + 1) % MAX;
    return servedCustomer;
}

int main()
{
    struct Queue ticketCounter;
    initQueue(&ticketCounter);

    enqueue(&ticketCounter, 1);
    enqueue(&ticketCounter, 2);
    enqueue(&ticketCounter, 3);

    printf("Serving customer %d\n", dequeue(&ticketCounter));
    printf("Serving customer %d\n", dequeue(&ticketCounter));

    enqueue(&ticketCounter, 4);
    enqueue(&ticketCounter, 5);
    enqueue(&ticketCounter, 6);
    enqueue(&ticketCounter, 7);
    enqueue(&ticketCounter, 8); // Queue is full
    enqueue(&ticketCounter, 9); // Queue is full
    printf("Serving customer %d\n", dequeue(&ticketCounter));
    printf("Serving customer %d\n", dequeue(&ticketCounter));
    printf("Serving customer %d\n", dequeue(&ticketCounter));
    printf("Serving customer %d\n", dequeue(&ticketCounter));

    return 0;
}
