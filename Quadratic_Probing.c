#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE] = {NULL};

void insert()
{

    int key, index, i, flag = 0, hkey;
    printf("\nEnter a value to insert: ");

    scanf("%d", &key);
    hkey = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++)
    {

        index = (hkey + i * i) % TABLE_SIZE;

        if (h[index] == NULL)
        {
            h[index] = key;
            break;
        }
    }
    if (i == TABLE_SIZE)
        printf("\nElement cannot be inserted\n");
}
void search()
{

    int key, index, i, flag = 0, hkey;
    printf("\nEnter the element to search: ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i * i) % TABLE_SIZE;
        if (h[index] == key)

        {
            printf("Value is found at index %d", index);
            break;
        }
    }
    if (i == TABLE_SIZE)
        printf("\nValue not found\n");
}
void display()
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < TABLE_SIZE; i++)

        printf("\nIndex %d:\t%d", i, h[i]);
}
void main()
{
    int opt, i;
    while (1)
    {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &opt);
        switch (opt)

        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            exit(0);
        }
    }
}
