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
}node;

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
    tree pnode = malloc(sizeof(node));
    pnode->elem = el;
    pnode->left = NULL;
    pnode->right = NULL;

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
int size(tree t){
    if(!t)
        return 0;
    else
        return (size(t->left) + 1 + size(t->right));
}

/**
 * calculate depth of tree
 * @param t pointer to tree
 * @return int with max depth
 */
int maxDepth(tree t){
    if(!t)
        return 0;
    else{
        int lDepth = maxDepth(t->left);
        int rDepth = maxDepth(t->right);
        
        if(lDepth > rDepth) return (lDepth + 1);
        else return (rDepth + 1);
    }
}

/**
 * print the tree with preorder method
 * @param t
 */
void preOrder(tree t) {
    if(t) {
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