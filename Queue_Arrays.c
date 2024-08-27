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

int Enqueue(int *array, int size)
{
    int item;

    if (rear == size - 1)
    {
        printf("Queue is full. Cannot enqueue.\n");
        return -1;
    }

    printf("Enter the element to enqueue: ");
    scanf("%d", &item);

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        array[rear] = item;
    }
    else
    {
        rear = (rear + 1) % size;
        array[rear] = item;
    }

    return 0;
}

int Dequeue(int *array, int size)
{
    int item;

    if (front == -1 && rear == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    item = array[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    printf("Dequeued element: %d\n", item);

    front--;
    rear--;

    for (int i = 0; i < size ; i++)
        {
            array[i] = array[i + 1];
        }
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
            PrintQueue(queue);
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