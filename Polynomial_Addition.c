#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

struct Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

struct Node* CreateNode(struct Node*);
struct Node* SortPolynomial(struct Node*);
struct Node*  AddPolynomial();
void ShowPolynomial(struct Node*);

struct Node* CreateNode(struct Node *poly)
{
    int x, y;
    printf("coefficient: ");
    scanf("%d", &x);
    printf("Power: ");
    scanf("%d", &y);
    struct Node *new = (struct Node *)malloc(sizeof(struct Node)), *current;
    if(new == NULL){
        printf("\nMemory error\n");
        exit(0);
    }
    new->coeff = x;
    new->pow = y;
    new->next = NULL;
    if (poly == NULL)
    {
        poly = new;
    }
    else
    {
        current = poly;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new;
    }
    poly = SortPolynomial(poly);
    return poly;
}

struct Node* SortPolynomial(struct Node *poly){
    struct Node *current, *temp, *bubble;int buff;
    for (current = poly; current != NULL; current = current->next)
        {
            bubble = current;
            for (temp = current->next; temp != NULL; temp = temp->next)
            {
                if (temp->pow > bubble->pow)
                {
                    bubble = temp;
                }
            }
            buff = current->pow;
            current->pow = bubble->pow;
            bubble->pow = buff;
        }
    return poly;
}

struct Node* AddPolynomial(struct Node* poly1, struct Node* poly2)
{
    struct Node *poly3 = NULL, *current = NULL;

    while (poly1 != NULL && poly2 != NULL)
    {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL)
        {
            printf("\nMemory error\n");
            exit(0);
        }

        if (poly1->pow > poly2->pow)
        {
            newNode->pow = poly1->pow;
            newNode->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow)
        {
            newNode->pow = poly2->pow;
            newNode->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else
        {
            newNode->pow = poly1->pow;
            newNode->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        newNode->next = NULL;

        if (poly3 == NULL)
        {
            poly3 = newNode;
            current = poly3;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }

    while (poly1 != NULL)
    {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL)
        {
            printf("\nMemory error\n");
            exit(0);
        }

        newNode->pow = poly1->pow;
        newNode->coeff = poly1->coeff;
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;

        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL)
        {
            printf("\nMemory error\n");
            exit(0);
        }

        newNode->pow = poly2->pow;
        newNode->coeff = poly2->coeff;
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;

        poly2 = poly2->next;
    }

    return poly3;
}
void ShowPolynomial(struct Node *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next != NULL){
                printf(" + ");
        }
        poly = poly->next;
    }
}

int main()
{
    printf("\n====================================================\n");
    printf("Enter the coefficients and powers for the first poly: \n");
    while (1)
    {
        poly1=CreateNode(poly1);
        char choice;
        printf("Do you want to add another term (y/n)? ");
        scanf(" %c", &choice);
        if (choice == 'n')
            break;
    }
    printf("\nEnter the coefficients and powers for the second poly: \n");
    while (1)
    {
        poly2=CreateNode(poly2);
        char choice;
        printf("Do you want to add another term (y/n)? ");
        scanf(" %c", &choice);
        if (choice == 'n')
            break;
    }
    printf("\nFirst polynomial: ");
    ShowPolynomial(poly1);
    printf("\nSecond polynomial: ");
    ShowPolynomial(poly2);
    printf("\nResultant poly: ");
    poly3 = AddPolynomial(poly1, poly2);
    ShowPolynomial(poly3);
    printf("\n================================================\n");
    return 0;
}
