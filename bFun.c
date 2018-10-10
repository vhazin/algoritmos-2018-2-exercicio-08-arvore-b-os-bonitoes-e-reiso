#include <stdio.h>
#include <stdlib.h>
#include "bFun.h"

#define M 3

void create(bTree *Tree, int order) // recebe ponteiro para arvore
{
    node *new = (node *)malloc(sizeof(node)); //cria node
    new->isLeave = TRUE;
    new->nKeys = 0;
    Tree->root = new;
    Tree->order = order;
}

void splitChild(node *father, int position, int order)
{
    int j, t = (order - 1) / 2;
    node *new = (node *)malloc(sizeof(node));
    node *child = father->childs[position];
    new->isLeave = child->isLeave;
    new->nKeys = t;
    for (j = 1; j < t; j++)
}

void insert(bTree *myTree, int value)
{
    node *Root = myTree->root;

    if (Root->nKeys)
    {
        node *newroot = (node *)malloc(sizeof(node));
        myTree->root = newroot;
        newroot->isLeave = FALSE;
        newroot->nKeys = 0;
        newroot->keys[0] = Root;
        splitChild(newroot, 1);
        insertNonfull(s, value);
    }
    else
    {
        insertNonfull(Root, value);
    }
}

int insertNonfull(node *Node, int value)
{
    int i = Node->nKeys;

    if (Node->isLeave)
    {
        while (i >= 0 && value < Node->keys[i])
        {
            Node->keys[i + 1] = Node->keys[i];
            i--;
        }
        Node->keys[i + 1] = value;
        Node->nKeys = Node->nKeys + 1;
    }
    else
    {
        while (i >= Node->nKeys && value < Node->keys[i])
        { // descobrir condicional de i
            i--;
        }
        i++;
        if (/* condition */)
        { // completar
            /* code */
        }
    }
}
