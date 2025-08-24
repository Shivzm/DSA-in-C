// Find min and max element in a BST iteratively

#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    int data;
    struct BstNode *left, *right;
};

struct BstNode *root = NULL;

struct BstNode *GetNewNode(int data) {
    struct BstNode *newNode = malloc(sizeof *newNode);
    if (!newNode) exit(1);
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Insert(int data) {
    struct BstNode *newNode = GetNewNode(data);
    if (root == NULL) {
        root = newNode;
        return;
    }

    struct BstNode *parent = NULL;
    struct BstNode *curr = root;

    while (curr != NULL) {
        parent = curr;
        if (data < curr->data) {
            curr = curr->left;
        } else if (data > curr->data) {
            curr = curr->right;
        } else {
           
            free(newNode);
            return;
        }
    }

    if (data < parent->data) parent->left = newNode;
    else parent->right = newNode;
}

int FindMin(struct BstNode *root) {

   struct BstNode *current = root;
   while(current -> left != NULL) {
     current = current -> left;
   }

   return  current -> data;
}

int FindMax(struct BstNode *root) {

    struct BstNode *current = root;
   while(current -> right != NULL) {
     current = current -> right;
   }

   return current -> data; 
}

int main () {

    Insert(12);
    Insert(13);
    Insert(14);
    Insert(16);
    
    printf("The Minimum term in the Binary Search Tree is: %d\n", FindMin(root));
     printf("The Maximum term in the Binary Search Tree is: %d\n", FindMax(root));

    return 0;
}