#include <stdio.h>
#include "bFun.h"

int main(void)
{
    bTree *myTree = (bTree *)malloc(sizeof(bTree));
    int order, value;
    scanf("%d", &value);
    order = value;
    create(myTree, order);
    while (TRUE)
    {
        scanf("%d", &value);
        if (!value)
            break;
        insert(myTree, value);
    }
    print(myTree->root);
    return 0;
}