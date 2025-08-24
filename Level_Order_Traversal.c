// Level order tree traversal

#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *left, *right;
};

struct node *root = NULL;

/* Queue node storing pointers to tree nodes */
struct Qnode {
    struct node *treeNode;
    struct Qnode *next;
};

struct Qnode *qfront = NULL;
struct Qnode *qrear = NULL;

/* queue operations for tree nodes */
int isQueueEmpty(void) {
    return qfront == NULL;
}

void enqueue(struct node *tnode) {
    struct Qnode *temp = malloc(sizeof *temp);
    if (!temp) { perror("malloc"); exit(1); }
    temp->treeNode = tnode;
    temp->next = NULL;
    if (qrear == NULL) {
        qfront = qrear = temp;
        return;
    }
    qrear->next = temp;
    qrear = temp;
}

struct node *dequeue(void) {
    if (qfront == NULL) return NULL;
    struct Qnode *temp = qfront;
    struct node *ret = temp->treeNode;
    qfront = qfront->next;
    if (qfront == NULL) qrear = NULL;
    free(temp);
    return ret;
}

/* tree helpers */
struct node *GetNewNode(char data) {
    struct node *newNode = malloc(sizeof *newNode);
    if (!newNode) { perror("malloc"); exit(1); }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


void Insert(char data) {
    struct node *newNode = GetNewNode(data);
    if (root == NULL) {
        root = newNode;
        return;
    }

    struct node *parent = NULL;
    struct node *curr = root;
    while (curr != NULL) {
        parent = curr;
        if (data < curr->data) curr = curr->left;
        else if (data > curr->data) curr = curr->right;
        else { /* duplicate */
            free(newNode);
            return;
        }
    }

    if (data < parent->data) parent->left = newNode;
    else parent->right = newNode;
}

/* Level order traversal using the queue above */
void LevelOrder(struct node *root) {
    if (root == NULL) return;
    /* ensure queue is empty */
    while (!isQueueEmpty()) dequeue();

    enqueue(root);
    while (!isQueueEmpty()) {
        struct node *curr = dequeue();
        printf("%c ", curr->data); // print character, not numeric ASCII
        if (curr->left) enqueue(curr->left);
        if (curr->right) enqueue(curr->right);
    }
    printf("\n");
}

int main() {
    
    Insert('F');
    Insert('D');
    Insert('J');
    Insert('B');
    Insert('E');
    Insert('G');
    Insert('K');
    Insert('A');
    Insert('C');
    Insert('I');
    Insert('H');

    printf("Level order traversal: ");
    LevelOrder(root);

    return 0;
}