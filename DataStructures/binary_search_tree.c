#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Tree{
    double value;
    struct Tree* left;
    struct Tree* right;
};

/*
   =======
   Helpers
   =======
*/

struct Tree* createNode(double value) {
    struct Tree* node = (struct Tree*) malloc(sizeof(struct Tree));
    node->value = value;
    return node;
}


/*
   =========
   Utilities
   =========
*/

struct Tree* insertNode(struct Tree* root, double value) {
    struct Tree *node = createNode(value);
    struct Tree *temp = root, *prev;

    /* Empty Tree */
    if (root == NULL) return node;

    /* Traverse Tree */
    while(temp != NULL) {
        prev = temp; // Set current to previous node
        temp = (temp->value > value) ? temp->left : temp->right ; // Get next node
    }

    /* Print Value */
    if (prev->value > value)
        prev->left = node;
    else
        prev->right = node;

    return root;
}

void deleteNode(struct Tree* root, double value) {
}

/*
   ==========
   Traversals
   ==========
*/

/* Left Mid Right */
void infix(struct Tree* node) {
    if(node == NULL) {
        return;
    }
    infix(node->left);
    printf("%0.3lf ", node->value);
    infix(node->right);
}
/* Left Right Mid */
void postfix(struct Tree* node) {
    if(node == NULL) {
        return;
    }
    postfix(node->left);
    postfix(node->right);
    printf("%0.3lf ", node->value);
}
/* Mid Left Right */
void prefix(struct Tree* node) {
    if(node == NULL) {
        return;
    }
    printf("%0.3lf ", node->value);
    prefix(node->left);
    prefix(node->right);
}

int main() {

    struct Tree* root = createNode(30);

    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 7);
    insertNode(root, 3);

    infix(root);

    getchar();

};
