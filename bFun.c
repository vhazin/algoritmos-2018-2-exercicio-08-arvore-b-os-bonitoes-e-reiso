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


void insert(bTree *myTree, int value) {
    node *Root = myTree->root;

    if (root->nKeys == ) {
        node *newroot = (node*)malloc(sizeof(node));
        myTree->root = newroot;
        newroot->isLeave = FALSE;
        newroot->nKeys = 0;
        newroot->keys[0] = Root;
        splitChild(newroot, 1);
        insertNonfull(s, value);
    }else {
        insertNonfull(Root, value);
    }
}


int insertNonfull(node *Node, value) {
    int i = Node->nKeys;

    if (Node->isLeave) {
        while (i >= 0 && value < Node->keys[i]) {
            Node->keys[i+1] = Node->keys[i];
            i--;
        }
        Node->keys[i+1] = value;
        Node->nKeys = Node->nKeys + 1;
    }else {
        while (i >= Node->nKeys && k < Node->keys[i]) {     // descobrir condicional de i
            i--;
        }
        i++;
        if (/* condition */) {     // completar
            /* code */
        }
    }
}
