#include <stdio.h>
#include <stdlib.h>
#include "bFun.h"

#define M 3

void create(bTree *Tree) // recebe ponteiro para arvore
{
    node *new = (node *)malloc(sizeof(node)); //cria node
    new->isLeave = TRUE;
    new->nKeys = 0;
    Tree->root = x;
}

int search(node *x, int k)
{
    int i = 0;

    while (i <= x->nKeys && k > x->keys[i])
    {
        if (i <= x->nKeys &&k = x->keys[i])
        {
            return (x, i);
        }
        i += 1;
    }

    if (x->isLeave)
    {
        return NULL;
    }
}
