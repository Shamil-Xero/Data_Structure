#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *tail;

void CreateHeadNode();
void InsertNode();
void DeleteNode();
void DisplayNodes();
void SearchNode();
void SortNodes();
void CloneLinkedList();

void main()
{
    int choice;
    printf("\n\n---------- Linked list -----------\n");
    CreateHeadNode();
    do
    {
        printf("\n\n1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the nodes\n");
        printf("4. Search for a node\n");
        printf("5. Sort the nodes\n");
        printf("6. Clone the Linked List\n");
        printf("0. Exit...\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsertNode();
            break;
        case 2:
            DeleteNode();
            break;
        case 3:
            DisplayNodes();
            break;
        case 4:
            SearchNode();
            break;
        case 5:
            SortNodes();
            break;
        case 6:
            CloneLinkedList();
            break;
        case 0:
            printf("\nExiting...\n\n");
            break;
        default:
            printf("\n\nInvalid choice. Please try again...\n");
        }
    } while (choice != 0);
}

void DisplayNodes()
{
    printf("\n\n--------------------------------\n");
    struct node *current = head;
    printf("Linked List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
    printf("\n\n--------------------------------\n");
}

void CreateHeadNode()
{
    printf("\n\n--------------------------------\n");
    printf("Enter data to create Head node: ");
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Memory error!\n");
        return;
    }
    scanf("%d", &head->data);
    head->next = NULL;
    printf("Head node created with data: %d\n", head->data);
    printf("\n\n--------------------------------\n");
}

void InsertNode()
{
    printf("--------------------------------\n");
    printf("\nEnter the position of the node (-1 to add at the end): ");
    int position, i;
    scanf("%d", &position);
    printf("\nEnter the data of the node: ");
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Memory error!\n");
        return;
    }
    else
    {
        scanf("%d", &new->data);
    }

    if (position == 1)
    {
        new->next = head;
        head = new;
        printf("Node inserted at the start\n");
    }
    else if (position < 0)
    {
        struct node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new;
        new->next = NULL;
        printf("Node inserted at the end\n");
    }
    else
    {
        struct node *current = head;
        for (i = 1; i < position - 1; i++)
        {
            if (current->next == NULL)
            {
                break;
            }
            current = current->next;
        }
        if (current->next != NULL)
        {
            new->next = current->next;
            current->next = new;
            printf("Node inserted at position: %d\n", position);
        }
        else
        {
            printf("\nPosition Out of range! So node inserted\n");
        }
    }
    DisplayNodes();
}

void DeleteNode()
{
    printf("--------------------------------\n");
    printf("Enter the position of the node to delete (-1 to delete the last node): ");
    int position;
    scanf("%d", &position);
    struct node *current = head, *previous;
    if (position == 1)
    {
        head = current->next;
        printf("First node is deleted\n");
    }
    else if (position < 0)
    {
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        printf("Last node is deleted\n");
    }
    else
    {
        for (int i = 1; i < position; i++)
        {
            previous = current;
            current = current->next;
            if (current == NULL)
            {
                break;
            }
        }
        if (current != NULL)
        {
            previous->next = current->next;
            printf("\nNode on position %d is deleted\n", position);
        }
        else
        {
            printf("\nPosition Out of range! So node not deleted\n");
        }
    }
    free(current);
    DisplayNodes();
}

void SearchNode()
{
    printf("--------------------------------\n");
    printf("Enter the data to search: ");
    int search_data, found = 0, position = 0;
    scanf("%d", &search_data);
    struct node *current = head;
    while (current != NULL)
    {
        position++;
        if (current->data == search_data)
        {
            found = 1;
            break;
        }
        current = current->next;
    }
    if (found)
    {
        printf("\nNode with data %d found at position %d\n", search_data, position);
    }
    else
    {
        printf("\nNode with data %d not found\n", search_data);
    }
}

void SortNodes()
{
    printf("--------------------------------\n");
    printf("Ascending or descending order (A/D): ");
    char order;
    scanf(" %c", &order);
    printf("\nSorting the linked list...\n");
    struct node *current, *temp, *bubble;
    int buff;
    if (order == 'A')
    {
        for (current = head; current != NULL; current = current->next)
        {
            bubble = current;
            for (temp = current->next; temp != NULL; temp = temp->next)
            {
                if (temp->data < bubble->data)
                {
                    bubble = temp;
                }
            }
            buff = current->data;
            current->data = bubble->data;
            bubble->data = buff;
        }
        printf("\nLinked list sorted in ascending order.\n");
    }
    else if (order == 'D')
    {
        for (current = head; current != NULL; current = current->next)
        {
            bubble = current;
            for (temp = current->next; temp != NULL; temp = temp->next)
            {
                if (temp->data > bubble->data)
                {
                    bubble = temp;
                }
            }
            buff = current->data;
            current->data = bubble->data;
            bubble->data = buff;
        }
        printf("\nLinked list sorted in descending order.\n");
    }
    else
    {
        printf("\nInvalid order. Please enter 'A' for ascending or 'D' for descending.\n");
        return;
    }

    DisplayNodes();
}

void CloneLinkedList()
{
    printf("--------------------------------\n");
    printf("\nCloning the linked list...\n");
    struct node *current = head, *new, *cloned_head = NULL, *cloned_tail = NULL;
    while (current->next != NULL)
    {
        current = current->next;
    }
    tail = current;
    for (current = head; current != NULL; current = current->next)
    {
        new = (struct node *)malloc(sizeof(struct node));
        if (new == NULL)
        {
            printf("Memory error!\n");
            return;
        }
        new->data = current->data;
        if (cloned_head == NULL && cloned_tail == NULL)
        {
            new->next = NULL;
            cloned_tail = cloned_head = new;
        }
        else
        {
            new->next = NULL;
            cloned_tail->next = new;
            cloned_tail = new;
        }
    }
    tail->next = cloned_head;
    tail = cloned_tail;
    DisplayNodes();
}
