#include <stdio.h>  
int main ()  
{  
    int arr[20], i, j, k, size;  
    printf ("Define the number of elements in an array: ");  
    scanf ("%d", &size);  
    printf ("\nEnter the elements of an array:\n");  
    for ( i = 0; i < size; i++)
    {  
        scanf ("%d", &arr[i]);
    }  
    for ( i = 0; i < size; i ++)
    {  
        for ( j = i + 1; j < size; j++)  
        {  
            if ( arr[i] == arr[j])  
            {  
                for ( k = j; k < size - 1; k++)  
                {  
                    arr[k] = arr [k + 1];  
                }  
                size--;  
                j--;      
            }  
        }  
    }  
        for ( i = 0; i < size; i++)  
    {  
        printf ("%d  ", arr[i]);  
    }  
}
