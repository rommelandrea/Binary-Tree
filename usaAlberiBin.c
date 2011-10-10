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

    tree albero;

    albero = newTree();

    insert(&albero, 10);
    insert(&albero, 5);
    insert(&albero, 15);
    insert(&albero, 3);
    insert(&albero, 4);
    insert(&albero, 12);

    preOrder(albero);

    return (EXIT_SUCCESS);
}