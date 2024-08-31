#include<stdio.h>
int top = -1;

void Push();
int Pop(int *);
void Peek();
void Display();

int main() {
    printf("Enter the maximum size of the stack: ");
    int size, data;
    scanf("%d", &size);
    int stack[size],choice;
    do{
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
            printf("Enter the data to push: ");
            scanf("%d", &data);
                Push(stack, size, data);
                break;
            case 2:
                data = Pop(stack);
                printf("Popped Element: %d", data);
                break;
            case 3:
                Peek(stack);
                break;
            case 4:
                Display(stack);
                break;
            case 0:
                printf("\nExiting...\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 0);
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

void Display(int stack[]){
    if (top == -1) {
        printf("Stack is empty. Nothing to display.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void Peek(int stack[]){
    if (top == -1) {
        printf("Stack is empty. Nothing to peek.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}
