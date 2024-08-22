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

// Function to create new node
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
    // printf("\n%d\t%d\t%d\t%d\t%d", new);
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

struct Node*  AddPolynomial()
{
    struct Node *poly3 = (struct Node*)malloc(sizeof(struct Node)), *poly;
    poly3->next = NULL;
    poly = poly3;
    while (poly1->next!=NULL && poly2->next!=NULL)
    {
        if (poly1->pow > poly2->pow)
        {
            poly3->pow = poly1->pow;
            poly3->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        else if (poly1->pow < poly2->pow)
        {
            poly3->pow = poly2->pow;
            poly3->coeff = poly2->coeff;
            poly2 = poly2->next;
        }

        else
        {
            poly3->pow = poly1->pow;
            poly3->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        poly3->next = (struct Node *)malloc(sizeof(struct Node));
        poly3 = poly3->next;
        poly3->next = NULL;
    }
    while (poly1->next!=NULL || poly2->next!=NULL)
    {
        if (poly1->next!=NULL)
        {
            poly3->pow = poly1->pow;
            poly3->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next!=NULL)
        {
            poly3->pow = poly2->pow;
            poly3->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly3->next = (struct Node *)malloc(sizeof(struct Node));
        poly3 = poly3->next;
        poly3->next = NULL;
    }
    return poly;
}

void ShowPolynomial(struct Node *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next != NULL){
                printf("+");
        }
        poly = poly->next;
    }
}

int main()
{
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
    // poly3 = AddPolynomial();
    // printf("\nResultant poly: ");
    // ShowPolynomial(poly3);
    return 0;
}
