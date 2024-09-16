#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void DisplayNodes(node *head)
{
    printf("\n\n--------------------------------\n");
    node *current = head;
    printf("Doubly Linked List: ");
    if (head != NULL)
    {
        do
        {
            printf("%d <-> ", current->data);
            current = current->next;
        } while (current != head);
        printf("%d\n", current->data);
    }
    printf("\n\n--------------------------------\n");
}

void InsertNode(node **head, node **tail, int position, int data)
{
    printf("--------------------------------\n");
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Memory error!\n");
        return;
    }
    new->data = data;

    if (*head == NULL)
    {
        *head = *tail = new;
        new->prev = new->next = new;
        printf("Node created at the start\n");
    }
    else if (position == 0 || position == 1)
    {
        new->next = *head;
        new->prev = (*tail);
        (*head)->prev = new;
        (*tail)->next = new;
        *head = new;
        printf("Node inserted at the start\n");
    }
    else if (position < 0)
    {
        new->next = *head;
        new->prev = (*tail);
        (*head)->prev = new;
        (*tail)->next = new;
        *tail = new;
        printf("Node inserted at the end\n");
    }
    else
    {
        node *current = *head;
        for (int i = 1; i < position - 1; i++)
        {
            if (current->next == *head)
            {
                break;
            }
            current = current->next;
        }
        if (current->next != *head)
        {
            new->next = current->next;
            new->prev = current;
            current->next->prev = new;
            current->next = new;
            printf("Node inserted at position: %d\n", position);
        }
        else
        {
            printf("\nPosition Out of range!\n");
        }
    }
    // DisplayNodes(*head);
}

void DeleteNode(node **head, node **tail, int position)
{
    printf("--------------------------------\n");
    node *current = *head;
    if (position == 1)
    {
        if (*head == *tail)
        {
            free(*head);
            *head = *tail = NULL;
            printf("Head node is deleted\n");
        }
        else
        {
            *head = current->next;
            (*head)->prev = (*tail);
            (*tail)->next = *head;
            printf("First node is deleted\n");
        }
    }
    else if (position < 1)
    {
        while (current->next != *head)
        {
            current = current->next;
        }
        current->prev->next = *head;
        (*head)->prev = current->prev;
        *tail = current->prev;
        printf("Last node is deleted\n");
    }
    else
    {
        for (int i = 1; i < position; i++)
        {
            current = current->next;
            if (current == *head)
            {
                break;
            }
        }
        if (current != *head)
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (current == *tail)
            {
                *tail = current->prev;
            }
            printf("\nNode on position %d is deleted\n", position);
        }
        else
        {
            printf("\nPosition Out of range! So node not deleted\n");
        }
    }
    free(current);
    // DisplayNodes(*head);
}

void main()
{
    int choice, position, data;
    printf("\n\n---------- Doubly Linked List -----------\n");

    do
    {
        printf("\n\n1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the nodes\n");
        printf("0. Exit...\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the position of the node (-1 to add at the end): ");
            scanf("%d", &position);
            printf("\nEnter the data of the node: ");
            scanf("%d", &data);
            InsertNode(&head, &tail, position, data);
            break;
        case 2:
            printf("Enter the position of the node to delete (-1 to delete the last node): ");
            scanf("%d", &position);
            DeleteNode(&head, &tail, position);
            break;
        case 3:
            DisplayNodes(head);
            break;
        case 0:
            printf("\nExiting...\n\n");
            break;
        default:
            printf("\n\nInvalid choice. Please try again...\n");
        }
    } while (choice != 0);
}