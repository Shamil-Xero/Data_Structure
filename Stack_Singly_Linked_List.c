#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void Push()
{
    printf("Enter the value: ");
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Memory Error\n");
        return;
    }
    scanf("%d", &new->data);
    if (head == NULL)
    {
        head = new;
        new->next = NULL;
    }
    else
    {
        new->next = head;
        head = new;
    }
}

void Pop()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else if (head->next != NULL)
    {
        head = head->next;
    }
    else
    {
        head = NULL;
    }
    printf("Popped element is %d\n", temp->data);
    free(temp);
}

void Display()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Display();
            break;
        case 0:
            printf("\nExiting...\n\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

// void Peek()
// {
//     if (head == NULL)
//     {
//         printf("Stack is empty\n");
//     }
//     else
//     {
//         printf("Top element is %d\n", head->data);
//     }
// }
