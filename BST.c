#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BstNode {
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct BstNode *rootPtr = NULL;

struct BstNode *GetNewNode(int data) {
    struct BstNode *newNode = malloc(sizeof *newNode);
    if (!newNode) exit(1);
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Insert(int data) {
    struct BstNode *newNode = GetNewNode(data);
    if (rootPtr == NULL) {
        rootPtr = newNode;
        return;
    }

    struct BstNode *parent = NULL;
    struct BstNode *curr = rootPtr;

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

bool FindElement(int data) {
    struct BstNode *temp = rootPtr;
    while (temp != NULL) {
        if (data == temp->data) return true;
        if (data < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return false;
}

int main(void) {
    Insert(12);
    Insert(13);
    Insert(14);
    Insert(16);

    if (FindElement(16)) {
        printf("We found the value\n");
    } else {
        printf("We could not find the value\n");
    }
    return 0;
}