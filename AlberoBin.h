/* 
 * File:   AlberoBin.h
 * Author: Andrea Romanello
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node* tree;

tree newTree();
void insert(tree *, int);

void preOrder(tree);
void inOrder(tree);
void postOrder(tree);

