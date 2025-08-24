// Find Inorder successor in a Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* inorder successor in a Binary Search Tree - style consistent with your repo */

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
        else { /* duplicate */ free(newNode); return; }
    }

    if (data < parent->data) parent->left = newNode;
    else parent->right = newNode;
}

struct BstNode *FindNode(struct BstNode *root, int data) {
    struct BstNode *curr = root;
    while (curr != NULL) {
        if (data == curr->data) return curr;
        if (data < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    return NULL;
}

struct BstNode *FindMinNode(struct BstNode *node) {
    if (node == NULL) return NULL;
    while (node->left != NULL) node = node->left;
    return node;
}

/* If node->right exists, successor is min in right subtree.
   Otherwise, walk from root keeping the last node larger than target. */
struct BstNode *InorderSuccessor(struct BstNode *root, struct BstNode *n) {
    if (n == NULL) return NULL;
    if (n->right != NULL) return FindMinNode(n->right);

    struct BstNode *succ = NULL;
    struct BstNode *curr = root;
    while (curr != NULL) {
        if (n->data < curr->data) {
            succ = curr;
            curr = curr->left;
        } else if (n->data > curr->data) {
            curr = curr->right;
        } else break;
    }
    return succ;
}

void InorderPrint(struct BstNode *node) {
    if (!node) return;
    InorderPrint(node->left);
    printf("%d ", node->data);
    InorderPrint(node->right);
}

int main(void) {
    /* sample tree */
    Insert(20);
    Insert(8);
    Insert(22);
    Insert(4);
    Insert(12);
    Insert(10);
    Insert(14);

    printf("Inorder: ");
    InorderPrint(root);
    printf("\n");

    int queries[] = {8, 10, 14, 22, 100};
    for (size_t i = 0; i < sizeof queries / sizeof queries[0]; ++i) {
        int val = queries[i];
        struct BstNode *node = FindNode(root, val);
        if (!node) {
            printf("Node %d not found in tree\n", val);
            continue;
        }
        struct BstNode *succ = InorderSuccessor(root, node);
        if (succ) printf("Inorder successor of %d is %d\n", val, succ->data);
        else printf("Inorder successor of %d does not exist\n", val);
    }

    return 0;
}
