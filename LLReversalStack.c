// Reverse a Linked List using stack

#include <stdio.h>
#include <stdlib.h>
#define MAX 100


struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int x) {
    struct node *temp = malloc(sizeof *temp);
    if (!temp) return;
    temp->data = x;
    temp->next = head;
    head = temp;
}

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX - 1; }

void push(Stack *s, int v) { if (!isFull(s)) s->data[++s->top] = v; }
int pop(Stack *s) { return isEmpty(s) ? 0 : s->data[s->top--]; }

void reverseUsingStack(void) {
    Stack s;
    initStack(&s);
    struct node *curr = head;
    while (curr) { push(&s, curr->data); curr = curr->next; }
    curr = head;
    while (curr) { curr->data = pop(&s); curr = curr->next; }
}

void printList(void) {
    struct node *cur = head;
    while (cur) { printf("%d -> ", cur->data); cur = cur->next; }
    printf("NULL\n");
}

int main(void) {
    insert(1); insert(2); insert(3); insert(4);
    printf("Before: ");
    printList();
    reverseUsingStack();
    printf("After:  ");
    printList();
    return 0;
}