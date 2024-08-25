#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1, MAX=100;

void Push(char *, char);
void Pop(char *);
void Display(char *);

int main(){
    printf("\n================================\n");
    printf("Enter the String: ");
    char str[MAX], rev[MAX];
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        Push(rev, str[i]);
    }
    printf("Reversed String: ");
    for(int i = 0; i < len; i++){
        Pop(rev);
    }
    printf("\n================================\n");
    return 0;
}

void Push(char stack[], char l){
    if (top == MAX - 1) {
        printf("Stack Overflow! Increase the stack size.\n");
    } else {
        stack[++top] = l;
    }
}

void Pop(char stack[]){
    if (top == -1) {
        printf("Stack Underflow! Cannot pop an element.\n");
    } else {
        printf("%c", stack[top--]);
    }
}

void Display(char stack[]){
    if (top == -1) {
        printf("Stack is empty. Nothing to display.\n");
    } else {
        printf("Reversed String: ");
        for (int i = top; i >= 0; i--) {
            printf("%c", stack[i]);
        }
        printf("\n");
    }
}