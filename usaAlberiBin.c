/* 
 * File:   usaAlberoBin.c
 * Author: Andrea Romanello
 *
 */


#include "AlberoBin.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int n, d;
    tree albero;

    albero = newTree();
    
    printf("creato albero");
    
    printf("prova");

    insert(&albero, 10);
    insert(&albero, 5);
    insert(&albero, 15);
    insert(&albero, 3);
    insert(&albero, 4);
    insert(&albero, 12);
    insert(&albero, 9);
    insert(&albero, 8);
    insert(&albero, 7);
    insert(&albero, 6);
    insert(&albero, 16);
    insert(&albero, 17);
    insert(&albero, 18);
    insert(&albero, 20);
    insert(&albero, 19);
    insert(&albero, 29);
    insert(&albero, 25);
    insert(&albero, 13);
    
    
    preOrder(albero);

    n = size(albero);
    printf("numero nodi %d\n", n);

    d = maxDepth(albero);
    printf("altezza massima %d\n", d);

    return (EXIT_SUCCESS);
}