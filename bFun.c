#include "bFun.h"

void insertKey(node *root, int value, node *child) // insere uma chave nova
{
    int nKeys, pos;

    pos = searchPos(root, value);
    nKeys = root->nKeys;

    while (nKeys > pos && value < root->keys[nKeys - 1])
    {
        root->keys[nKeys] = root->keys[nKeys - 1];
        root->childs[nKeys + 1] = root->childs[nKeys];
        nKeys--;
    }

    root->keys[pos] = value;
    root->childs[pos + 1] = child;
    root->nKeys++;
}

node *insertAtNode(node *root, int value, char *isLeave, int *valueReturned) // insere um valor no nó
{
    int i, j, pos,
        halfValue;
    node *temp, *child;

    if (root == NULL)  // se a raiz for vazia então insere o primeiro valor dela
    {

        *isLeave = TRUE;
        *valueReturned = value;
        return (NULL);
    }
    else  // se não, insere mais valores
    {
        pos = searchPos(root, value); // pega posição do nó
        if (root->nKeys > pos && root->keys[pos] == value) // se tiver um numero de chaves maior que a posição
        {                                                  // o nó deixa de ser folha
            *isLeave = FALSE;
        }
        else
        {

            child = insertAtNode(root->childs[pos], value, isLeave, valueReturned);
            if (*isLeave)
            {
                if (root->nKeys < ORDER - 1)
                {
                    insertKey(root, *valueReturned, child);
                    *isLeave = FALSE;
                }
                else
                {
                    temp = (node *)malloc(sizeof(node));
                    temp->nKeys = 0;

                    for (i = 0; i < ORDER; i++)
                        temp->childs[i] = NULL;

                    halfValue = root->keys[(ORDER / 2)];

                    temp->childs[0] = root->childs[(ORDER / 2) + 1];
                    for (i = (ORDER / 2) + 1; i < ORDER - 1; i++)
                        insertKey(temp, root->keys[i], root->childs[i + 1]);

                    for (i = (ORDER / 2); i < ORDER - 1; i++)
                    {
                        root->keys[i] = 0;
                        root->childs[i + 1] = NULL;
                    }
                    root->nKeys = (ORDER / 2);

                    if (pos <= (ORDER / 2))
                        insertKey(root, *valueReturned, child);
                    else
                        insertKey(temp, *valueReturned, child);

                    *valueReturned = halfValue;
                    return (temp);
                }
            }
        }
    }
}

node *insertValue(node *root, int value) // insere valor no nó
{
    char isLeave;
    int valueReturned, i;
    node *child, *newRoot;

    child = insertAtNode(root, value, &isLeave, &valueReturned);
    if (isLeave)
    {
        newRoot = (node *)malloc(sizeof(node));
        newRoot->nKeys = 1;
        newRoot->keys[0] = valueReturned;
        newRoot->childs[0] = root;
        newRoot->childs[1] = child;
        for (i = 2; i <= ORDER - 1; i++)
            newRoot->childs[i] = NULL;
        return (newRoot);
    }
    else
        return (root);
}

int searchPos(node *no, int value)  // procura posição do nó e valor
{
    int meio, i, f;

    i = 0;
    f = no->nKeys - 1;

    while (i <= f)
    {
        meio = (i + f) / 2;
        if (no->keys[meio] == value)
            return (meio);
        else if (no->keys[meio] > value)
        {
            f = meio - 1;
        }
        else
        {
            i = meio + 1;
        }
    }
    return (i);
}

void print(node *root) // printa a arvore
{
    int i;
    if (root != NULL)
    {
        printf("[");
        for (i = 0; i < root->nKeys; i++)
        {
            printf(" %d ", root->keys[i]);
        }
        printf("]");
        for (i = 0; i <= root->nKeys; i++)
        {
            print(root->childs[i]);
        }
    }
}
