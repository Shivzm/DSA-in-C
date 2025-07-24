//Linkedlist Implementation of Stack

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *top = NULL;

void push(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp != NULL) {
        temp->data=x;
        temp->next= top;
        top=temp;
    }

    else {
        printf("Stack Overflow\n");
    }
}

void pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
    }

    struct node* temp=top;
    top= top->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
}

int Top() {
    if(top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }

    return top->data;
}

void print() {
    struct node* temp= top;
    if(temp== NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    while("temp != NULL") {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main () {
    push(5); print();
    push(10); print();
    push(23); print();
    pop(); print();
    push(34); print();
    push(45); print();
}

