#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a stack node for actions (type or delete)
struct Node
{
    char action; // 't' for type, 'd' for delete
    char character;
    struct Node *next;
};

// Initialize an empty stack
struct Node *Stack = NULL;

// Function to push an action onto the stack
void push(char action, char character)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->action = action;
    new->character = character;
    new->next = Stack;
    Stack = new;
}

// Function to pop the action from the stack
void pop()
{
    if (Stack != NULL)
    {
        struct Node *temp = Stack;
        Stack = Stack->next;
        free(temp);
    }
}

// Function to undo the last action
void undo()
{
    if (Stack != NULL)
    {
        char action = Stack->action;
        char character = Stack->character;
        pop(); // Remove the top action from the stack

        if (action == 't')
        {
            // Undo typing: Remove the last character
            // Implement your own text buffer here
            printf("Undo typing: Remove '%c'\n", character);
        }
        else if (action == 'd')
        {
            // Undo deletion: Add back the deleted character
            // Implement your own text buffer here
            printf("Undo deletion: Add back '%c'\n", character);
        }
    }
    else
    {
        printf("Nothing to undo.\n");
    }
}

int main()
{
    // Example usage
    push('t', 'H'); // Types 'H'
    push('t', 'e'); // Types 'e'
    push('d', 'e'); // Deletes 'e'
    push('t', 's'); // Types 's'

    // Undo the last action
    undo();
    undo();

    return 0;
}
