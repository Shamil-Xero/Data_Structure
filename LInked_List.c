#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void CreateHeadNode();

void InsertNode();
void DeleteNode();
void DisplayList();

void main() {
    int choice;
    printf("\n\n---------- Linked list -----------\n");
    CreateHeadNode();
    do{
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("0. Exit...\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                InsertNode();
                break;
            case 2:
                // head = DeleteNode(head);
                break;
            case 3:
                DisplayList();
                break;
            case 0:
                printf("\nExiting...\n\n");
                break;
            default:
                printf("\n\nInvalid choice. Please try again...\n");
        }
    } while (choice != 0);
}

void CreateHeadNode(){
    printf("\n\n--------------------------------\n");
    printf("Enter data to create Head node: ");
    head = (struct node *) malloc(sizeof(struct node));
    if (head == NULL){
        printf("Memory error!\n");
        return;
    }
    scanf("%d", &head->data);
    head->next = NULL;
    printf("Head node created with data: %d\n", head->data);
}

void InsertNode(){
    printf("--------------------------------\n");
    printf("Enter the position of the node: ");
    int position;
    scanf("%d", &position);
    printf("Enter the data of the node: ");
    struct node *new = (struct node *) malloc(sizeof(struct node));
    if (new == NULL){
        printf("Memory error!\n");
        return;
    }else{
        scanf("%d", &new->data);
    }

    if (position < 1){
        position = 1;
        new->next = head;
        head = new;
        printf("Node inserted at the start with data: %d\n", new->data);
    }
}


void DisplayList() {
    struct node *current =  (struct node *) malloc(sizeof(struct node));
    if (current == NULL){
        printf("Memory error!\n");
    }else{
        printf("--------------------------------\n");
        printf("Displaying the list...\n");
        current = head;
        while (current != NULL){
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}
