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

int Priority_Enqueue(int *array, int size, int data)
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
        if (data >= array[front])
        {
            for(int i = rear; i >= front; i--){
                if(data >= array[i]){
                    for(int j = rear; j > i; j--){
                        array[j+1] = array[j];
                    }
                    array[i+1] = data;
                    break;
                }
            }
        }
        else
        {
            for (int i = rear; i >= front; i--)
            {
                array[i + 1] = array[i];
            }
            array[front] = data;
        }
        rear = (rear + 1) % size;
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

    ShiftLeft(array, size, 0);
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
            printf("Enter the element to enqueue: ");
            int data;
            scanf("%d", &data);
            Priority_Enqueue(queue, size, data);
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