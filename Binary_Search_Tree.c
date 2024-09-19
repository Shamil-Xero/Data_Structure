#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Creating a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inserting a node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// In-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, data;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value to insert: ");
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nIn-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");
    printf("\nPre-order traversal of the BST: ");
    preOrderTraversal(root);
    printf("\n");
    printf("\nPost-order traversal of the BST: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
