//Inserting a note at nth position of a linked list

#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *head; // declaration of head pointer as a global variable

void insert(int data, int n) {
     struct node *temp1=(struct node*)malloc(sizeof(struct node));
        temp1->data = data;
        temp1->next = NULL;
        if (n == 1) {
            temp1->next = head; // Point new node to the current head
            head = temp1; // Update head to new node
            return;
            } 
            
            struct node *temp2 = head;
            for (int i = 1; i < n - 1 && temp2 != NULL; i++) {
                temp2 = temp2->next; // Traverse to the (n-1 th) node
            }
            
            temp1->next = temp2->next; // Point new node to the next node
            temp2->next = temp1; // Link the (n-1 th) node to the new node 
}
void print() {
    struct node *temp = head;
    printf("List is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next; // Move to the next node
    }
    printf("\n");
}

int main () {
    head = NULL;
    insert(10, 1); // Insert 10 at position 1
    insert(20, 2); // Insert 20 at position 2
    insert(30, 1); // Insert 30 at position 1
    insert(40, 3); // Insert 40 at position 3
    print(); // Print the linked list
}