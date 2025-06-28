#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // strdup, strcmp

////////////////////////////////////////////////////////////////////////////////
// structure definition

typedef struct NODE
{
	int data;
	struct NODE	*left;
	struct NODE	*right;
} NODE;

typedef struct
{
	int count;
	NODE *root;
} TREE;

////////////////////////////////////////////////////////////////////////////////
// internal(node related) functions declaration

NODE *_makeNode(int data)
{
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) return NULL;

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

// used in BST_Insert
static void _insert( NODE *root, NODE *pNode)
{
    if(pNode->data < root->data){
        if(root->left == NULL)
            root->left = pNode;
        else
            _insert(root->left, pNode);
    }
    else{
        if(root->right == NULL)
            root->right = pNode;
        else
            _insert(root->right, pNode);
    }
}

// used in BST_Destroy
static void _destroy( NODE *root)
{
    if(!root) return;

    _destroy(root->left);
    _destroy(root->right);

    free(root);
}

void _traverse( NODE *root)
{
    if (root == NULL) return;

    _traverse(root->left);
    _traverse(root->right);
    printf("%d\n", root->data);
}


////////////////////////////////////////////////////////////////////////////////
// BST function declarations

TREE *BST_Create(void)
{
    TREE *newtree = (TREE*)malloc(sizeof(TREE));
    if (newtree == NULL) return NULL;

    newtree->count = 0;
    newtree->root = NULL;

    return newtree;
}

void BST_Destroy( TREE *pTree)
{
    _destroy(pTree->root);
    free(pTree);
}

void BST_Traverse( TREE *pTree)
{
    _traverse(pTree->root);
}

static void BST_Insert( TREE *pTree, int X)
{
    NODE *newnode = _makeNode(X);
    if (!newnode) return;

    if(pTree->root == NULL){
        pTree->root = newnode;
    }
    else{
        _insert(pTree->root, newnode);
    }
}

////////////////////////////////////////////////////////////////////////////////
// Main

int main(void){
    TREE *BST = BST_Create();
    int value;

    while(scanf("%d", &value) != EOF) {
        BST_Insert(BST, value);
    }

    BST_Traverse(BST);

    BST_Destroy(BST);
    return 0;
}