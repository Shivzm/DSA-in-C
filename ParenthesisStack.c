#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int top = -1;
char stack[MAX];

int isEmpty() {
    if(top == -1) {
        return 1;
    }
    else {
         return 0;
    }
}

int isFull() {
    if(top == MAX-1) {
        return 1;
    }
    else {
        return 0;
    }
     
}

int match_char(char a, char b) {
    if(a == '{' && b == '}') {
        return 1;
    }
    if(a == '[' && b == ']') {
        return 1;
    }
    if(a == '(' && b == ')') {
        return 1;
    }     
    return 0;
}
void push(char c) {
    if(isFull()) {
        printf("Stack Overflow");
        exit(1);
    }
    top++;
    stack[top]= c;
}
char pop() {
    char c;
    if(isEmpty()) {
        printf("Stack Underflow");
        exit(1);
    }
    c = stack[top];
    top--;

    return c;
     

}

int check_balance(char *c) {
    int i;
    char temp;

    for( i=0; i<(int)strlen(c); i++) {
        if(c[i]== '{' || c[i]== '[' || c[i]== '(') {
            push(c[i]);
        }
        else if(c[i]== '}' || c[i]== ']' || c[i]== ')') {
            
            if(isEmpty()) {
                printf("Right brackets are more than left brackets.\n");
                return 0;
              }
             temp =pop();
             if(!match_char(temp, c[i])) {
                 printf("Brackets Mismatch.\n");
                 return 0;
                }
                
            }
    }
   
    if(isEmpty()) {
        printf("Brackets Are  Well Balanced.\n");
        return 1;
    }
    else{
        printf("Left Brackets Are More than the right. \n");
        return 0;
    }
  
}

int main () {
    char expr[MAX];
    int balanced;
    printf("Enter an Algebraic Expression: ");
    if (!fgets(expr, sizeof expr, stdin)) return 1;
    expr[strcspn(expr, "\n")] = '\0';
    
    
    balanced = check_balance(expr);
    if(balanced == 1)
    printf("The Expression is valid.\n");
    else
    printf("The Expression is invalid. \n");
    return 0;
}