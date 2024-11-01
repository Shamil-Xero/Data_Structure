#include <stdio.h>
#include <stdlib.h>

int front = -1; int rear = -1, size;

int *initArray(int size){
    int *array = calloc(size, sizeof(int));
    return array;
}

void PrintQueue(int *queue, int size)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    int i;
    for (i = front; i != rear; i = ( i + 1 ) % size)
    {
        printf("%d\t", queue[i]);
    }
    printf("%d\n", queue[i]);
}

int Enqueue(int *array, int size, int data)
{
   
    if ((rear + 1) % size == front)
    {
        printf("Queue is full. Cannot enqueue.\n");
        return -1;
    }
    
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;    
    }    
    array[rear] = data;
    return 0;
}

int Dequeue(int *array, int size)
{

    if (front == -1 && rear == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }    
    
    printf("Dequeued element: %d\n", array[front]);
    
    if (front == rear)
    {
        front = rear = -1;    
    }
    else
    {
        front = (front + 1) % size;    
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *queue = initArray(size);

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
            printf("Enter the element to enqueue: ");
            int data;
            scanf("%d", &data);
            Enqueue(queue, size, data);
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
