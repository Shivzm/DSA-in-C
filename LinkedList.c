//inserting a node at the beginning of a linked list

#include<stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head; //declaration of head pointer as a global variable
void insert(int x) {
     struct node *temp=(struct node*)malloc(sizeof(struct node));
     temp -> data = x;
     temp -> next = head;
     head=temp;
}
void print()
 {
    struct node *temp=head;
    printf("List is:");
    while(temp!= NULL){
        printf("%d", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
 }
int main (){
    head = NULL;
    int n,x,i;
    printf("Enter number of elements\n");
    scanf("%d", &n);

    for(i = 0; i<n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        insert(x);
        print();
    }   
}