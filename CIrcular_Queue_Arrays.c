#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size;

int *CreateArray(int *array, int size)
{
    array = (int *)malloc(size * sizeof(int));
    return array;
}

void ShiftLeft(int *array, int size, int index)
{
    for (int i = index; i < size; i++)
    {
        array[i] = array[i + 1];
    }
}

void PrintQueue(int *queue, int size)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    int i = front;
    do
    {
        printf("%d\t", queue[i]);
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    printf("\n");
}

int Enqueue(int *array, int size)
{
    int data;

    if ((rear + 1) % size == front)
    {
        printf("Queue is full. Cannot enqueue.\n");
        return -1;
    }

    printf("Enter the element to enqueue: ");
    scanf("%d", &data);

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
    int data;

    if (front == -1 && rear == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    data = array[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    printf("Dequeued element: %d\n", data);
    return 0;
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *queue = CreateArray(queue, size);

    do
    {
        printf("\n1. Display\n2. Enqueue\n3. Dequeue\n0. Exit\n");
        printf("Your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            PrintQueue(queue, size);
            break;
        case 2:
            Enqueue(queue, size);
            break;
        case 3:
            Dequeue(queue, size);
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