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
        if (value == 0)
            break;
        insert(myTree, value);
        printf("inseri\n");
    }
    print(myTree->root);
    return 0;
}