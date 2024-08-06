#include<stdio.h>
int main(){
    int A[10][10],B[10][10],C[10][10],r,c,i,j,k;
    printf("\n\nEnter the number of rows = ");
    scanf("%d",&r);
    printf("Enter the number of columns = ");
    scanf("%d",&c);
    printf("Enter the first matrix element=\n");
    for(i=0;i<r;i++){
        for(j=0 ; j<c ; j++){
            scanf("%d",&A[i][j]);
        }
    }    
    printf("Enter the second matrix element=\n");
    for(i=0 ; i<r ; i++){
        for(j=0;j<c;j++){
            scanf("%d",&B[i][j]);
        }
    }
    printf("Multiplication of the Matrices = \n");
    for(i=0 ; i<r ; i++){
        for(j=0;j<c;j++){
            C[i][j]=0;
            for(k=0;k<c;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

    for(i=0 ; i<r ; i++){    
        for(j=0 ; j<c ; j++){    
            printf("%d\t",C[i][j]);    
        }    
        printf("\n");    
    }    
    return 0;  
}  
