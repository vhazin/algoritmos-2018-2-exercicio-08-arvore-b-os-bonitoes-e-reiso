#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

#ifndef __BFUN__
#define __BFUN__

typedef struct node_s
{
    int nKeys;
    int *keys;
    char isLeave;
} node;

typedef struct bTree_s
{
    struct node_s *root;
    int order;
} bTree;

void create();

#endif