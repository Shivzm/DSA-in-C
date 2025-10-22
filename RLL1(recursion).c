// Reverse a linked list using recursion
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

void ReverseList(struct node *p) {
    if(p->next == NULL) {
        head = p;
        return;
    }

    ReverseList(p->next);
    struct node *q = p->next;
    q->next = p;
    p->next = NULL;
}

void print(struct node *n) {
    while(n!= NULL) {
        printf("%d", n->val);
        n = n->next;
        if(n != NULL) {
            printf(" -> ");
        }
    }
}

int main () {
    struct node *temp1, *temp2;
    head = (struct node*)malloc(sizeof(struct node*));
    head-> val=1;
    head->next=NULL;
    temp1 = head;
    for(int i =2; i <= 10; i += 2) {
        temp2 = (struct node*)malloc(sizeof(struct node*));
        temp2->val = i;
        temp2->next = NULL;
        temp1->next = temp2;
        temp1 = temp2;
    }
    
    printf("Original List: ");
    print(head);
    ReverseList(head);
    printf("\nReversed List: ");
    print(head);
    printf("\n");
    return 0;
    
}
