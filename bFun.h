#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

#define MAX_KEYS 99
#define MAX_CHILDS 100

#ifndef __BFUN__
#define __BFUN__

typedef struct node_s
{
    int nKeys;
    int keys[MAX_KEYS];
    struct node_s *childs[MAX_CHILDS];
    char isLeave;
} node;

typedef struct bTree_s
{
    struct node_s *root;
    int order;
} bTree;

void create();

#endif