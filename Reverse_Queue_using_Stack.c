#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size, top = -1;

int *CreateArray(int size)
{
    int *array = (int *)malloc(size * sizeof(int));
    return array;
}

void ShiftLeft(int *array, int size, int index)
{
    for (int i = index; i < size; i++)
    {
        array[i] = array[i + 1];
    }
}

void PrintQueue(int *queue)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
    printf("\n");
}

void Push(int stack[], int size, int data)
{
    if (top == size - 1)
    {
        printf("Stack Overflow! Cannot push more elements.\n");
    }
    else
    {
        stack[++top] = data;
    }
}

int Pop(int stack[])
{
    if (top == -1)
    {
        printf("Stack Underflow! Cannot pop an element.\n");
    }
    else
    {
        return stack[top--];
    }
    return 0;
}

void ReverseQueueUsingStack(int *array, int size)
{
    int *stack = CreateArray(size);
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    while (front != rear)
    {
        Push(stack, size, Dequeue(array, size));
    }
    Push(stack, size, Dequeue(array, size));
    front = rear = -1;
    while (top != -1)
    {
        Enqueue(array, size, Pop(stack));
    }
}

int Enqueue(int *array, int size, int data)
{
    if (rear == size - 1)
    {
        printf("Queue is full. Cannot enqueue.\n");
        return -1;
    }

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        array[rear] = data;
    }
    else
    {
        rear = (rear + 1) % size;
        array[rear] = data;
    }
    return 0;
}

int Dequeue(int *array, int size)
{

    if (front == -1 && rear == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = array[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    for (int i = front; i <= rear; i++)
    {
        array[i - 1] = array[i];
    }

    front--;
    rear--;

    return data;
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *queue = CreateArray(size);

    do
    {
        printf("\n1. Display\n2. Enqueue\n3. Dequeue\n4. Reverse\n0. Exit\n");
        printf("Your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            PrintQueue(queue);
            break;
        case 2:
            printf("Enter the element to enqueue: ");
            int data;
            scanf("%d", &data);
            Enqueue(queue, size, data);
            break;
        case 3:
            data = Dequeue(queue, size);
            printf("Dequeued data: %d", data);
            break;
        case 4:
            ReverseQueueUsingStack(queue, size);
            break;
        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    free(queue);
}