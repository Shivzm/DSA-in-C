// deleting a node from binary search tree

#include <stdio.h>
#include <stdlib.h>

struct BstNode {
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
    if (root == NULL) { root = newNode; return; }

    struct BstNode *parent = NULL;
    struct BstNode *curr = root;
    while (curr != NULL) {
        parent = curr;
        if (data < curr->data) curr = curr->left;
        else if (data > curr->data) curr = curr->right;
        else { free(newNode); return; } /* duplicate */
    }

    if (data < parent->data) parent->left = newNode;
    else parent->right = newNode;
}

struct BstNode *FindMinNode(struct BstNode *node) {
    if (node == NULL) return NULL;
    while (node->left != NULL) node = node->left;
    return node;
}

/* recursive delete that returns the (possibly new) subtree root */
struct BstNode *DeleteNode(struct BstNode *node, int data) {
    if (node == NULL) return NULL;

    if (data < node->data) {
        node->left = DeleteNode(node->left, data);
    } else if (data > node->data) {
        node->right = DeleteNode(node->right, data);
    } else {
        /* found node to delete */
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        } else if (node->left == NULL) {
            struct BstNode *tmp = node->right;
            free(node);
            return tmp;
        } else if (node->right == NULL) {
            struct BstNode *tmp = node->left;
            free(node);
            return tmp;
        } else {
            struct BstNode *succ = FindMinNode(node->right);
            node->data = succ->data;
            node->right = DeleteNode(node->right, succ->data);
        }
    }
    return node;
}

/* wrapper that updates global root */
void Delete(int data) {
    root = DeleteNode(root, data);
}

void Inorder(struct BstNode *node) {
    if (node == NULL) return;
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}

int main(void) {
    Insert(12); Insert(5); Insert(3); Insert(7);
    Insert(18); Insert(15); Insert(20);

    printf("Inorder before delete: ");
    Inorder(root);
    printf("\n");

    Delete(3);   /* leaf */
    Delete(18);  /* node with two children */
    Delete(12);  /* root */

    printf("Inorder after delete:  ");
    Inorder(root);
    printf("\n");

    return 0;
}