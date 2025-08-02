#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node *prev;
};

struct node* head;

struct node* GetNewNode(int x) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void InsertAtHead(int x) {
    struct node* newNode = GetNewNode(x);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void InsertAtTail(int x) {
    struct node* newNode = GetNewNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void print() {
    struct node* temp = head;
    printf("Forward:");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void ReversePrint() {
    struct node* temp = head;
    if (temp == NULL) return;

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward:");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

int main() {
    head = NULL;
    InsertAtHead(10); print(); ReversePrint();
    InsertAtHead(20); print(); ReversePrint();
    InsertAtHead(30); print(); ReversePrint();
    InsertAtTail(40); print(); ReversePrint();
    InsertAtTail(50); print(); ReversePrint();
    InsertAtTail(60); print(); ReversePrint();
}