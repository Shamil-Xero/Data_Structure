#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Structure for a tree node
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Function to get the height of a node
int getHeight(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum value between two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to create a new node
Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Function to perform a right rotation
Node *rightRotate(Node *x)
{
    Node *y = x->left;
    // Node *T2 = y->right;

    x->left = y->right;
    y->right = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to perform a left rotation
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    // Node *T2 = y->left;

    y->left = x;
    x->right = y->left;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to get the balance factor of a node
int getBalance(Node *node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to find the node with the minimum value in the AVL tree
Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to insert a data into the AVL tree
Node *insert(Node *node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to delete a data from the AVL tree
Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {
            Node *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform in-order traversal of the AVL tree
void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        struct timespec ts = {1, 0};

        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform pre-order traversal of the AVL tree
void preOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        struct timespec ts = {1, 0};

        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal of the AVL tree
void postOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        struct timespec ts = {1, 0};

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main()
{
    Node *root = NULL;
    int n, data;

    // printf("Enter the number of nodes to insert: ");
    // scanf("%d", &n);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter value to insert: ");
    //     scanf("%d", &data);
    //     root = insert(root, data);
    // }
    root = insert(root, 45);
    root = insert(root, 48);
    root = insert(root, 21);
    root = insert(root, 23);
    root = insert(root, 47);
    root = insert(root, 50);

    printf("\n\nIn-order traversal of the AVL tree: ");
    inOrderTraversal(root);
    printf("\n\nPre-order traversal of the AVL tree: ");
    preOrderTraversal(root);
    printf("\n\nPost-order traversal of the AVL tree: ");
    postOrderTraversal(root);

    printf("\n\nEnter the data to delete: ");
    scanf("%d", &data);
    root = deleteNode(root, data);

    printf("\n\nIn-order traversal of the AVL tree after deletion: ");
    inOrderTraversal(root);

    return 0;
}