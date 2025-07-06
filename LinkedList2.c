// Delete a node at nth position of a linked list

#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void insert(int data) {
    struct node *temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = data;
    temp1->next = NULL;
    int n;
    
    if (n == 1) {
        temp1->next = head; // Point new node to the current head
        head = temp1; // Update head to new node
        return;
    }
    
    struct node *temp2 = head;
     for (int i = 1; i < n - 1; i++) {
        temp2 = temp2->next; // Traverse to the (n-1 th) node
    }
    
    temp1->next = temp2->next; // Point new node to the next node
    temp2->next = temp1; // Link the (n-1 th) node to the new node 
}

void delete(int n) {
    struct node *temp1 = head;
    if(n==1) {
        head = temp1->next; // Update head to the next node
        free(temp1); // Free the memory of the deleted node
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        temp1 = temp1->next; // Traverse to the (n-1 th) node
    }
    
    struct node *temp2 = temp1->next; // Node to be deleted
    temp1->next = temp2->next; // Link the (n-1 th) node to the (n+1 th) node
    free(temp2); // Free the memory of the deleted node
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
    insert(4);
    insert(7);
    insert(9);
    insert(2);
    print();

    int n;
    printf("Enter a position\n");
    scanf("%d", &n);
    delete(n);
    print();
}