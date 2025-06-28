#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    void *data;
    struct NODE *left;
    struct NODE *right;
}NODE;

typedef struct TREE{
    int count;
    NODE *root;
}TREE;

TREE *createTree(void);

int main(void){
    TREE *tree = createTree();

    return 0;
}

TREE *createTree(void)
{
    TREE *newtree = (TREE*)malloc(sizeof(TREE));
    if (newtree == NULL) return NULL;

    newtree->count = 0;
    newtree->root = NULL;

    return newtree;
}