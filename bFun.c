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
    printf("splitei i\n");
    int count;
    int t = order / 2;
    node *new = (node *)malloc(sizeof(node));
    printf("splitei ia\n");
    node *child;
    if (father->isLeave)
    {
        new->nKeys = t;
        printf("splitei ixaaa\n");
        for (count = 0; count < (t); count++)
            new->childs[count] = child->childs[count + t + 1];
        child->nKeys = t;
        for (count = father->nKeys + 1; count > (position - 1); count--)
            father->keys[count + 1] = father->keys[count];
        father->keys[position] = child->keys[t + 1];
        father->nKeys += 1;
    }
    else
    {
        child = father->childs[position];
        printf("Aaaaaaaaa\n");
        printf("aaa");
        new->isLeave = child->isLeave;
        printf("splitei ib\n");
        new->nKeys = t;
        printf("splitei ix\n");
        for (count = 0; count < (t); count++)
            new->keys[count] = child->keys[count + t + 1];
        printf("splitei iz\n");
        child->nKeys = t;
        for (count = father->nKeys + 1; count > (position - 1); count--)
            father->keys[count + 1] = father->keys[count];
        father->keys[position] = child->keys[t + 1];
        father->nKeys += 1;
        printf("splitei f\n");
    }
}

void insert(bTree *myTree, int value) // função para inserir novo nó
{

    node *Root = myTree->root;
    int t = myTree->order / 2;
    if (Root->nKeys >= myTree->order - 1)
    {
        node *newroot = (node *)malloc(sizeof(node));
        newroot->isLeave = FALSE;
        newroot->nKeys = 1;
        newroot->keys[0] = Root->keys[t]; // ver aqui
        myTree->root = newroot;
        splitChild(newroot, 0, myTree->order); // quando chama a função, newroot pode esta causando erro
        insertNonfull(newroot, value, myTree->order);
    }
    else
    {
        insertNonfull(Root, value, myTree->order);
    }
}

void insertNonfull(node *Node, int value, int order) // inserir se ja tiver outros valores no nó
{
    printf("inserteiNFull order: %d %d i\n", order, Node->isLeave);
    int numkey = Node->nKeys;
    int t = order / 2;

    if (Node->isLeave)
    {
        while (numkey >= 0 && value < Node->keys[numkey - 1])
        {
            Node->keys[numkey] = Node->keys[numkey - 1];
            numkey--;
        }
        Node->keys[numkey] = value;
        Node->nKeys = Node->nKeys + 1;
    }
    else
    {
        printf("CAI NO ELSE DA INSERTFull\n");
        while (numkey >= Node->nKeys && value < Node->keys[numkey - 1])
            numkey--;
        if (Node->childs[numkey]->nKeys >= order - 1)
        {
            splitChild(Node, numkey, order);
            if (value > Node->keys[numkey])
                numkey += 1;
        }
        insertNonfull(Node->childs[numkey], value, order);
    }
    printf("inserteiNFull f\n");
}

void print(node *root)
{
    printf("\nprintei i\n");
    int i;
    if (root != NULL)
    {
        printf("[");
        for (i = 0; i < root->nKeys; i++)
        {
            // print(root->childs[i]);
            printf(" %d ", root->keys[i]);
        }
        printf("]");
        if (!(root->isLeave))
        {
            for (i = 0; i <= root->nKeys; i++)
            {
                print(root->childs[i]);
            }
        }
        // print(root->childs[i]);
    }
    printf("\nprintei f\n");
}
