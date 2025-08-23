// Reversing a string using stack

#include<stdio.h>
#include<string.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} CharStack;

void initStack(CharStack *s) {
    s->top = -1;
}

int isEmpty(CharStack *s) {
    return s->top == -1;
}

int isFull(CharStack *s) {
    return s->top == MAX - 1;
}

void push(CharStack *s, char c) {
    if (!isFull(s)) {
        s->data[++(s->top)] = c;
    }
}

char pop(CharStack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0'; // Return null char if stack is empty
}

void reverse(char c[], int n) {
    CharStack A;
    initStack(&A);
    for(int i=0; i<n;i++) {
        push(&A, c[i]);
    }
    for(int i=0; i<n;i++) {
        c[i] = pop(&A);
    }
}

int main () {
    char c [40];
    printf("Enter a string: ");
    scanf("%s", &c);
    reverse(c, strlen(c));
    printf("OUTPUT: %s", c);
}