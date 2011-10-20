/* 
 * File:   AlberoBin.h
 * Author: Andrea Romanello
 *
 * include all method to use a binary search tree
 */
#include "AlberoBin.h"

struct node {
    int elem;
    tree left, right;
} node;

/**
 * create new tree
 * @return null
 */
tree newTree() {
    return NULL;
}

/**
 * create new node in tree
 * @param el int element to insert
 * @return return pointer to new node
 */
tree newNode(int el) {
    tree pnode;

    if (!(pnode = malloc(sizeof (node)))) {
        printf("\nerror malloc");
        exit(EXIT_FAILURE);
    } else {
        pnode->elem = el;
        pnode->left = NULL;
        pnode->right = NULL;
    }
    return pnode;
}

/**
 * insert element el in tree
 * @param t tree pointer
 * @param el int element to insert
 */
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

/**
 * count how many node are in the tree
 * @param t tree pointer
 * @return int number of node
 */
int size(tree t) {
    if (!t)
        return 0;
    else
        return (size(t->left) + 1 + size(t->right));
}

/**
 * calculate depth of tree
 * @param t pointer to tree
 * @return int with max depth
 */
int maxDepth(tree t) {
    if (!t)
        return 0;
    else {
        int lDepth = maxDepth(t->left);
        int rDepth = maxDepth(t->right);

        if (lDepth > rDepth) return (lDepth + 1);
        else return (rDepth + 1);
    }
}

/**
 * print the tree with preorder method
 * @param t
 */
void preOrder(tree t) {
    if (t) {
        printf("%d\n", t->elem);
        preOrder(t->left);
        preOrder(t->right);
    }
}

/**
 * print the tree with inorder method
 * @param t
 */
void inOrder(tree t) {
    if (t) {
        inOrder(t->left);
        printf("%d\n", t->elem);
        inOrder(t->right);
    }
}

/**
 * print the tree with postorder method
 * @param t
 */
void postOrder(tree t) {
    if (t) {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d\n", t->elem);
    }
}

/**
 * print tree rotated 90 degree
 * @param t tree pointer
 * @param h int value of height, initial value = 0
 */
void printRotated(tree t, int h) {
    int i;
    if (t) {
        printRotated(t->right, h + 1);
        for (i = 0; i <= h; i++)
            printf("\t");
        printf("%d\n", t->elem);
        printRotated(t->left, h + 1);
    }
}

/**
 * copy a tree
 * @param al pointer to original tree
 * @return new tree
 */
tree copy(tree al) {
    if (al)
        return copyNode(al->elem, copy(al->left), copy(al->right));
    else
        return al;
}

/**
 * create a copy of node
 * @param x value of node
 * @param t1 value of left
 * @param t2 value of right
 * @return 
 */
tree copyNode(int x, tree t1, tree t2) {
    tree al = newNode(x);
    al->left = t1;
    al->right = t2;

    return al;
}

/**
 * create a new speculate tree
 * @param t pointer to tree to copy speculate
 * @return return speculate tree
 */
tree speculate(tree t) {
    if (t)
        return copyNode(t->elem, speculate(t->right), speculate(t->left));
    else
        return t;
}

/**
 * speculate in place tree
 * @param t
 */
void flip(tree t) {
    if (t) {
        swap(&(t->left), &(t->right));
        flip(t->left);
        flip(t->right);
    }
}

/**
 * swap t1 to t2 and t2 to t1
 * @param t1
 * @param t2
 */
void swap(tree *t1, tree *t2) {
    tree temp;
    temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}

/**
 * check if t1 is equal t2
 * @param t1
 * @param t2
 * @return 
 */
int equals(tree t1, tree t2) {
    return ((t1 == t2) || (t1 && t2) && (t1->elem == t2->elem) && equals(t1->left, t2->left) && equals(t1->right, t2->right));
}

/**
 * check if t1 isSpeculate to t2
 * @param t1 tree 1
 * @param t2 tree 2
 * @return return 1 if equal 
 */
int isSpeculate(tree t1, tree t2) {
    return ((t1 == t2) || (t1 && t2) && (t1->elem == t2->elem) && isSpeculate(t1->left, t2->right) && isSpeculate(t1->right, t2->left));
}

/**
 * similar this method return true if the two tree in input have same form
 * @param t1 tree 1
 * @param t2 tree 2
 * @return return 1 if equals 0 on other case
 */
int similar(tree t1, tree t2) {
    return ((t1 == t2) == (t1 && t2) && similar(t1->left, t2->left) && similar(t1->right, t2->right));
}

/**
 * search element x in tree
 * @param x element searched
 * @param t tree pointer
 * @return 1 if find element 0 if it don't find it
 */
int find(int x, tree t) {
    return (t) && ((t->elem == x) || find(x, t->left) || find(x, t->right));
}