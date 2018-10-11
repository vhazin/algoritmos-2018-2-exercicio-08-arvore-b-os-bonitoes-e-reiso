#include <stdio.h>
#include <stdlib.h>
#include "bFun.h"

#define M 3
#define GMIN 2 // grau minimo da arvore (se precisar, fazer por metodo de input)

// tecnicamente funções que serão usadas no insert estão prontas

void create(bTree *Tree, int order) // recebe ponteiro para arvore
{
    node *new = (node *)malloc(sizeof(node)); //cria node
    new->isLeave = TRUE;
    new->nKeys = 0;
    Tree->root = new;
    Tree->order = order;
}


void splitChild(node *father, int position) // função para dar split
{
    int count;
    node *new = (node *)malloc(sizeof(node));
    node *child = father->childs[position];
    new->isLeave = child->isLeave;
    new->nKeys = GMIN - 1;
    for (count = 0; count < (GMIN - 1); count++)
        new->keys[count] = child->keys[count + GMIN];
    if (!child->isLeave)
    {
        for (count = 0; count < (GMIN-1); count++)
            new->childs[count] = child->childs[count+GMIN];
    }
    child->nKeys = GMIN - 1;
    for (count = father->nKeys+1; count > (position-1); count--)
        father->keys[count+1] = father->keys[count];
    father->keys[position] = child->keys[GMIN];
    father->nKeys += 1;
}


void insert(bTree *myTree, int value) // função para inserir novo nó
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


int insertNonfull(node *Node, int value) // inserir se ja tiver outros valores no nó
{
    int numkey = Node->nKeys;

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
        if (Node->childs[numkey]->nKeys == (2 * GMIN) - 1)
        {
            splitChild(Node, numkey);
            if (value > Node->keys[numkey])
                numkey += 1;
        }
        insertNonfull(Node->childs[numkey], value);
    }
}


void printar(bTree *raiz)
{
    int i;
    if (raiz->root != NULL)
    {
        for (i = 0; i < raiz->root->nKeys; i++)
        {
            printar(raiz->root->childs[i]);
            printf("\n%d", raiz->root->keys[i]);
        }
        printar(raiz->root->childs[i]);
    }
}


int main(void) {

}