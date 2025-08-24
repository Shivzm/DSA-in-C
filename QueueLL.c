// Linked List implementation of Queue

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *front = NULL;
struct node *rear = NULL;

void Enqueue(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node*));

    temp -> data = x;
    temp -> next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }

    rear -> next = temp;
    rear = temp;
}

void Dequeue() {
    struct node *temp = front;
    if(front == NULL) {
        return;
    }
    else if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front -> next;
    }

    free(temp);
}

int Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return 1;
	}
	return front->data;
}

void Print() {
	struct node* temp = front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();

    return 0;
}