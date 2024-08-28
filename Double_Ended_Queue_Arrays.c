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

int AddRight(int *array, int size, int data)
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

int AddLeft(int *array, int size, int data)
{
    if (rear == size - 1)
    {
        printf("Queue is full. Cannot enqueue.\n");
        return -1;
    }

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        array[front] = data;
    }
    else
    {
        for (int i = rear + 1; i >= front; i--)
        {
            array[i + 1] = array[i];
        }
        front = 0;
        array[front] = data;
        rear = (rear + 1) % size;
    }

    return 0;
}

int DelRight(int *array, int size)
{
    int data;

    if (front == -1 && rear == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    data = array[rear];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear - 1) % size;
    }

    printf("Dequeued element: %d\n", data);

}

int DelLeft(int *array, int size)
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
        printf("\n1. Display\n2. AddRight\n3. AddLeft\n4. DelRight\n5. DelLeft\n0. Exit\n");
        printf("Your choice: ");
        int choice, data;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            PrintQueue(queue);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            AddRight(queue, size, data);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            AddLeft(queue, size, data);
            break;
        case 4:
            DelRight(queue, size);
            break;
        case 5:
            DelLeft(queue, size);
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