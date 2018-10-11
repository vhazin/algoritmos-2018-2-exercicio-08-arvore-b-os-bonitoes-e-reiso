#include <stdio.h>
#include <stdlib.h>
#include "bFun.h"

void create(bTree *Tree, int order) // recebe ponteiro para arvore
{
    node *new = (node *)malloc(sizeof(node)); //cria node
    new->isLeave = TRUE;
    new->nKeys = 0;
    Tree->root = new;
    Tree->order = order;
}

void splitChild(node *father, int position, int order) // função para dar split
{
    int count;
    int t = (order - 1) / 2;
    node *new = (node *)malloc(sizeof(node));
    node *child = father->childs[position];
    new->isLeave = child->isLeave;
    new->nKeys = t;
    for (count = 0; count < (t); count++)
        new->keys[count] = child->keys[count + t + 1];
    if (!child->isLeave)
    {
        for (count = 0; count < (t); count++)
            new->childs[count] = child->childs[count + t + 1];
    }
    child->nKeys = t;
    for (count = father->nKeys + 1; count > (position - 1); count--)
        father->keys[count + 1] = father->keys[count];
    father->keys[position] = child->keys[t + 1];
    father->nKeys += 1;
}

void insert(bTree *myTree, int value) // função para inserir novo nó
{
    node *Root = myTree->root;
    int t = (myTree->order - 1) / 2;
    if (Root->nKeys >= 2 * t - 1)
    {
        node *newroot = (node *)malloc(sizeof(node));
        myTree->root = newroot;
        newroot->isLeave = FALSE;
        newroot->nKeys = 0;
        newroot->keys[0] = Root->keys[0];
        splitChild(newroot, 1, myTree->order);
        insertNonfull(newroot, value, myTree->order);
    }
    else
    {
        insertNonfull(Root, value, myTree->order);
    }
}

void insertNonfull(node *Node, int value, int order) // inserir se ja tiver outros valores no nó
{
    int numkey = Node->nKeys;
    int t = (order - 1) / 2;

    if (Node->isLeave)
    {
        while (numkey >= 0 && value < Node->keys[numkey])
        {
            Node->keys[numkey + 1] = Node->keys[numkey];
            numkey -= 1;
        }
        Node->keys[numkey + 1] = value;
        Node->nKeys = Node->nKeys + 1;
    }
    else
    {
        while (numkey >= Node->nKeys && value < Node->keys[numkey])
            numkey -= 1;
        numkey += 1;
        if (Node->childs[numkey]->nKeys == (2 * t) - 1)
        {
            splitChild(Node, numkey, order);
            if (value > Node->keys[numkey])
                numkey += 1;
        }
        insertNonfull(Node->childs[numkey], value, order);
    }
}

void print(node *root)
{
    int i;
    if (root != NULL)
    {
        for (i = 0; i < root->nKeys; i++)
        {
            print(root->childs[i]);
            printf("\n%d", root->keys[i]);
        }
        print(root->childs[i]);
    }
}
