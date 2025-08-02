// Pinting a Reverse Linked List using recursion
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void print(struct node* h) {
    if(h == NULL) {
        return;
    }
     printf("%d ", h->data);
    print(h->next); // Recursive call to print the next node

}

struct node* insert(struct node* head, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp; // If list is empty, new node becomes head
    } else {
        struct node* temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next; // Traverse to the end of the list
        }
        temp1->next = temp; // Link new node at the end
    }
    return head;
}

void ReversePrint(struct node* head) {
    if (head == NULL) {
        return; // Base case: if the list is empty, do nothing
    }

    ReversePrint(head->next); // Recursive call to print the next node
    printf("%d ", head->data); // Print the current node after returning from recursion
}

int main () {
    struct node* head = NULL;
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 6);
    head = insert(head, 8);
    head = insert(head, 10);
    
    printf("Original List: ");
    print(head);
    
    printf("\nReversed List: ");
    ReversePrint(head); // Print the list in reverse order using recursion
    printf("\n");
    
    return 0;
}