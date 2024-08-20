#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
};

struct node *head, *tail;

void CreateHeadNode();
void InsertNode();
void DeleteNode();
void DisplayNodes();
void SearchNode();
void SortNodes();
void ReverseLinkedList();

void main() {
    int choice;
    printf("\n\n---------- Linked list -----------\n");
    CreateHeadNode();
    do{
        printf("\n\n1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the nodes\n");
        printf("4. Search for a node\n");
        printf("5. Sort the nodes\n");
        printf("6. Reverse the linked list\n");
        printf("0. Exit...\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
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
                ReverseLinkedList();
                break;
            case 0:
                printf("\nExiting...\n\n");
                break;
            default:
                printf("\n\nInvalid choice. Please try again...\n");
        }
    } while (choice != 0);
}

void DisplayNodes(){
    printf("\n\n--------------------------------\n");
    struct node *current = head;
    printf("Linked List: ");
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("\n\n--------------------------------\n");
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
    head->prev = NULL;
    tail = head;
    printf("Head node created with data: %d\n", head->data);
    printf("\n\n--------------------------------\n");

}

void InsertNode(){
    printf("--------------------------------\n");
    printf("\nEnter the position of the node (0 to add at the end): ");
    int position, i;
    scanf("%d", &position);
    printf("\nEnter the data of the node: ");
    struct node *new = (struct node *) malloc(sizeof(struct node));
    if (new == NULL){
        printf("Memory error!\n");
        return;
    }else{
        scanf("%d", &new->data);
    }

    if (position == 1) {
        new->next = head;
        new->prev = NULL;
        if (head != NULL) {
            head->prev = new;
        }
        head = new;
        printf("Node inserted at the start\n");
    }else if (position < 0){
        tail->next = new;
        new->prev = tail;
        new->next = NULL;
        tail = new;
        printf("Node inserted at the end\n");
    }else {
        struct node *current = head;
        for (i = 1; i < position - 1; i++) {
            if (current->next == NULL){
                break;
            }
            current = current->next;
        }
        if (current->next != NULL){
            new->next = current->next;
            new->prev = current;
            current->next = new;
            new->next->prev = new;
            printf("Node inserted at position: %d\n", position);
        } else {
            printf("\nPosition Out of range! So no node was inserted\n");
        }
    }
    DisplayNodes();
}

void DeleteNode(){
    printf("--------------------------------\n");
    printf("Enter the position of the node to delete: ");
    int position;
    scanf("%d", &position);
    struct node *current, *previous;
    if (position == 1){
        current = head;
        if (current->next != NULL){
            current->next->prev = NULL;
        }
        head = current->next;
        printf("First node is deleted\n");
    } else if (position < 0){
        current = tail;
        if (current->prev != NULL){
            current->prev->next = NULL;
        }
        tail = current->prev;
        printf("Last node is deleted\n");
    } else {
        current = head;
        for (int i = 1; i < position; i++) {
            if (current == NULL){
                break;
            }
            current = current->next;
        }
        if (current != NULL){
            current->next->prev = current->prev;
            current->prev->next = current->next;
            printf("\nNode on position %d is deleted\n", position);
        }
        else {
            printf("\nPosition Out of range! So node not deleted\n");
        }
    }
    free(current);
    DisplayNodes();
}

void SearchNode(){
    printf("--------------------------------\n");
    printf("Enter the data to search: ");
    int search_data, found = 0, position = 0;
    scanf("%d", &search_data);
    struct node *current = head;
    while(current != NULL){
        position++;
        if(current->data == search_data){
            found = 1;
            break;
        }
        current = current->next;
    }
    if(found){
        printf("\nNode with data %d found at position %d\n", search_data, position);
    } else {
        printf("\nNode with data %d not found\n", search_data);
    }
    printf("\n--------------------------------\n");
}

void SortNodes() {
    printf("--------------------------------\n");
    printf("Ascending or descending order (A/D): ");
    char order;
    scanf(" %c", &order);
    printf("\nSorting the linked list...\n");
    struct node *current, *temp, *bubble;
    int buff;
    if (order == 'A') {
        for (current = head; current!= NULL; current = current->next) {
            bubble = current;
            for (temp = current->next; temp!= NULL; temp = temp->next) {
                if (temp->data < bubble->data) {
                    bubble = temp;
                }
            }
            buff = current->data;
            current->data = bubble->data;
            bubble->data = buff;
        }
        printf("\nLinked list sorted in ascending order.\n");
    }else if (order == 'D') {
        for (current = head; current!= NULL; current = current->next) {
            bubble = current;
            for (temp = current->next; temp!= NULL; temp = temp->next) {
                if (temp->data > bubble->data) {
                    bubble = temp;
                }
            }
            buff = current->data;
            current->data = bubble->data;
            bubble->data = buff;
        }
        printf("\nLinked list sorted in descending order.\n");
    }else {
        printf("\nInvalid order. Please enter 'A' for ascending or 'D' for descending.\n");
        return;
    }
    
    DisplayNodes();
}

void ReverseLinkedList(){
    printf("--------------------------------\n");
    printf("\nReversing the linked list...\n");
    struct node *current = head, *temp;
    tail = current;
    for(current = head; current != NULL; current = current->prev) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        head = current;
    }
    DisplayNodes();
}