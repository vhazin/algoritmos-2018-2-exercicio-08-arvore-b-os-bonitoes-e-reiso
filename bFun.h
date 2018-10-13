#include <stdio.h>
#include <stdlib.h>

#ifndef __BFUN__
#define __BFUN__

#define ORDER 5

#define TRUE 1
#define FALSE 0

typedef struct node_s
{
    int nKeys;
    int keys[ORDER - 1];
    struct node_s *childs[ORDER];
} node;

void insertKey(node *root, int value, node *child);
node *insertAtNode(node *root, int value, char *isLeave, int *valueReturned);
node *insertValue(node *root, int value);
int searchPos(node *no, int value);
void print(node *root);

#endif