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

int size(tree);
int maxDepth(tree);

void preOrder(tree);
void inOrder(tree);
void postOrder(tree);

void printRotated(tree, int);

tree copy(tree);
tree copyNode(int, tree, tree);
tree speculate(tree);
