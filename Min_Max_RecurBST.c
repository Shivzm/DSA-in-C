#include<stdio.h>
#include<stdlib.h>

struct BstNode {
    int data;
    struct BstNode *left, *right;
};

struct BstNode *root = NULL;

struct BstNode* GetNewNode(int data) {
       struct BstNode* newNode = malloc(sizeof(struct BstNode));
       if(!newNode) exit(1);
       newNode -> data = data;
       newNode -> left = newNode -> right = NULL;
       
       return newNode;
}

void Insert(int data) {
    struct BstNode *newNode = GetNewNode(data);

    if(root == NULL) {
        root = newNode;
        return;
    }

    struct BstNode *parent = NULL;
    struct BstNode *curr = root;
   
    while(curr != NULL) {
        parent = curr;

        if(data < curr -> data) {
            curr = curr -> left;
        }
        else if (data > curr -> data) {
            curr = curr->right;
        }
        else {
            free(newNode);
            return;
        }
    }

    if(data < parent -> data) parent -> left = newNode;
    else parent -> right = newNode;
    
}

int FindMin(struct BstNode *root) {

    struct BstNode *Root = root;
    if(Root == NULL) {
        printf("Error: Tree is empty");
        return -1;
    }
    else if (Root -> left == NULL) {
        return Root ->data;
    }
   
    return FindMin(Root -> left);
}

int FindMax(struct BstNode *root) {

    struct BstNode *Root = root;
    if(Root == NULL) {
        printf("Error: Tree is empty");
        return -1;
    }
    else if (Root -> right == NULL) {
        return Root ->data;
    }
   
    return FindMax(Root -> right);
}

int main () {

    Insert(4);
    Insert(12);
    Insert(34);
    Insert(49);
    Insert(54);

    printf("The Minimum value of the Binary Search Tree is: %d\n", FindMin(root));
    printf("The Maximum value of the Binary Search Tree is: %d\n", FindMax(root));

}