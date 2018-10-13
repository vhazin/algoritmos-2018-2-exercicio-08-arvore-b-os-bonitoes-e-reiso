#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bFun.h"

int main(void)
{
    node *root;
    int value;

    root = NULL;

    while (1)
    {
        scanf("%d", &value);
        if (!value)
            break;
        root = insertValue(root, value);
    }
    print(root);

    return (0);
}