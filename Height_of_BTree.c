// Find height of a binary tree

#include <stdio.h>
#include <stdlib.h>

struct BtNode {
    int data;
    struct BtNode *left, *right;
};

struct BtNode *root = NULL;

#define max(a,b) ((a) > (b) ? (a) : (b))

struct BtNode *GetNewNode(int data) {
    struct BtNode* newNode = malloc(sizeof *newNode);
    if (!newNode) exit(1);
    newNode->data = data;              
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Insert(int data) {
    struct BtNode* newNode = GetNewNode(data);

    if (root == NULL) {
        root = newNode;
        return;
    }

    struct BtNode* parent = NULL;
    struct BtNode* curr = root;

    
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

int FindHeight(struct BtNode* root) {
    if (root == NULL) {
        return -1; 
    }

    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main(void) {
    Insert(2);
    Insert(24);
    Insert(45);
    Insert(80);
    Insert(98);
    Insert(56);
    Insert(44);

    printf("The Height of the Binary tree is: %d\n", FindHeight(root));
    return 0;
}