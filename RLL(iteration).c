//Reverse a Linked List using iteration
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

struct node *head; // declaration of head pointer as a global variable

struct node* reverse(struct node* head) {
    struct node *current, *prev, *next;
    current = head;
    prev = NULL;

    while(current!= NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move to next node
    }
    
    head = prev; // Update head to the new first node   
    return head;
}

struct node* insert(struct node* head, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp; // If list is empty, new node becomes head
    } else {
        struct node *temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next; // Traverse to the end of the list
        }
        temp1->next = temp; // Link new node at the end
    }
    return head;
}

void print(struct node* head) { 
    while(head!= NULL) {

        printf("%d->", head->data);
        head = head->next; 
    }
}

int main () {
    struct node* head = NULL;
    head = insert(head,2);
    head = insert(head,4);
    head = insert(head,6);
    head = insert(head,8);
    head = insert(head,10);
    printf("Original List: ");
    print(head);
    printf("\n");
    printf("Reversed List: ");
    head = reverse(head);
    print(head);
    return 0;
}