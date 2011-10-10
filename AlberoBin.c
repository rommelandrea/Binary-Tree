#include "AlberoBin.h"

struct node {
    int elem;
    tree left, right;
}node;

tree newTree() {
    return NULL;
}

tree newNode(int el) {
    tree pnode = malloc(sizeof(node));
    pnode->elem = el;
    pnode->left = NULL;
    pnode->right = NULL;

    return pnode;
}

void insert(tree *t, int el) {
    if (*t) {
        if (el < (*t)->elem)
            insert(&((*t)->left), el);
        else if (el > (*t)->elem)
            insert(&((*t)->right), el);
        else
            (*t)->elem = el;
    } else *t = newNode(el);
}

void preOrder(tree t) {
    if(t) {
        printf("%d\n", t->elem);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void inOrder(tree t) {
    if (t) {
        inOrder(t->left);
        printf("%d\n", t->elem);
        inOrder(t->right);
    }
}

void postOrder(tree t) {
    if (t) {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d\n", t->elem);
    }
}