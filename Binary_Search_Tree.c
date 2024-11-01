#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *root = NULL;

// Creating a new node
Node *createNode(int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Inserting a node in the BST
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < (root)->data)
    {
        (root)->left = insert((root)->left, data);
    }
    else if(data > (root)->data)
    {
        (root)->right = insert((root)->right, data);
    }
    return root;
}

// Function to find the node with the minimum value in the BST
Node *minValue(Node *node)
{
    Node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
Node *delete(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = minValue(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void search(Node *root, int data){
    if(root==NULL)
        printf("Element not found\n");
    else if(data<root->data)
        search(root->left,data);
    else if(data>root->data)
        search(root->right,data);
    else
        printf("Element found\n");
}

// Traversal of the BST
void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
void preOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main()
{
    int n, data;

    // printf("Enter the number of nodes to insert: ");
    // scanf("%d", &n);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter value to insert: ");
    //     scanf("%d", &data);
    //     root = insert(root, data);
    // }

    root = insert(root, 20);
    root = insert(root, 65);
    root = insert(root, 4);
    root = insert(root, 21);
    printf("\n\nIn-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n\nPre-order traversal of the BST: ");
    preOrderTraversal(root);
    printf("\n\nPost-order traversal of the BST: ");
    postOrderTraversal(root);
    root = delete(root, 20);
    root = delete(root, 65);
    root = insert(root, 42);
    root = insert(root, 3);
    printf("\n\nAfter Deletion:");
    printf("\n\nIn-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n\n");


    return 0;
}
