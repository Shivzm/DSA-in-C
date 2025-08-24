// Stack Application Infix to Postfix conversion

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100

int stack[MAX];
char Infix[MAX], Postfix[MAX];
int top =-1;

int precedence(char symbol) {

    switch (symbol) {

    case '^': return 3;
    case '*':
    case '/': return 2;
    case '+':
    case '-': return 1;
    default: return 0;
    }
}

int isEmpty() {
    if(top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull() {
    return top == MAX-1;
}

void push(char c) {
     if(isFull()) {
        printf("Stack Overflow");
        exit(1);
     }
     stack[++top] = c;
}

char pop() {
    char c;
     if(isEmpty()) {
        printf("Stack Underflow");
        exit(1);
     }
     c=stack[top];
     top--;

     return c;
}

void InToPost() {
    int j=0;
    char symbol,next;
    for(int i=0; i<(int)strlen(Infix); i++) {
        symbol = Infix[i];

        switch(symbol) {
            case'(': 
            case'[':
            case'{': push(symbol);
                     break;
            case')': while((next =pop()) != '(') {
                     Postfix[j++] = next;
                    }
                     break;
            case']':while((next =pop()) != '[') {
                     Postfix[j++] = next;
                    };
                     break;
            case'}': while((next =pop()) != '{') {
                     Postfix[j++] = next;
                    };
                     break;
            case'+':
            case'-':
            case'*':
            case'/':
            case'^':         
                while (!isEmpty() && precedence(stack[top]) > precedence(symbol) || precedence(stack[top]) == precedence(symbol))
                {
                   Postfix[j++] = pop();
                }

                push(symbol);
                break;
                     
            default: Postfix[j++] = symbol;
                     break;     
        }
    }

    while(!isEmpty()) {
        Postfix[j++] = pop();
    }
    Postfix[j]= '\0';
    printf("Postfix Expression: %s\n", Postfix);
}

int Post_eval() {

    int a,b;

    for(int i=0; i<(int)strlen(Postfix); i++) {
        if(Postfix[i] >= '0' && Postfix[i] <= '9') {
            push(Postfix[i] - '0');
        }
        else {
            a=pop();
            b=pop();

            switch(Postfix[i]) {
                case '+': push(b+a);
                          break;
                case '-': push(b-a);
                          break;
                case '*': push(b*a);
                          break;
                case '/': push(b/a);
                          break;
                case '^': push(pow(b, a));
                          break;
            }
        }
    }

    return pop();
}

int main () {
    
    int result;
    printf("Enter the Infix Expression: ");
    if (!fgets(Infix, sizeof Infix, stdin)) return 1;
    Infix[strcspn(Infix, "\n")] = '\0';

    InToPost();
    result = Post_eval();
    printf("The restult obtained after postfix operation is: %d\n", result);
    return 0;
}