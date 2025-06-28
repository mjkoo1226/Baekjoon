#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *left;
    struct NODE *right;
} NODE;

typedef struct TREE {
    int count;
    NODE *root;
} TREE;

TREE *BST_create(void) {
    TREE *newtree = (TREE *)malloc(sizeof(TREE));
    if (newtree == NULL) return NULL;

    newtree->root = NULL;
    newtree->count = 0;

    return newtree;
}

NODE *makeNode(int data) {
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    if (newnode == NULL) return NULL;

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

NODE *_search(NODE *root, int key) {
    if (root == NULL) return NULL;

    if (root->data == key) return root;

    NODE *result = _search(root->left, key);
    if (result != NULL) return result;

    result = _search(root->right, key);
    return result;
}

void BST_insert(TREE *pTree, int parent, int data) {
    NODE *newnode = makeNode(data);
    if (parent == -1) { // 트리가 비어있고 루트 노드 삽입
        if (pTree->root == NULL) {
            pTree->root = newnode;
            pTree->count++;
        }
        return;
    }

    NODE *pPre = _search(pTree->root, parent);
    if (pPre == NULL) {
        free(newnode); // 부모 노드가 없는 경우 메모리 누수 방지
        return;
    }

    if (pPre->left == NULL)
        pPre->left = newnode;
    else if (pPre->right == NULL)
        pPre->right = newnode;

    pTree->count++;
}

void _delete_subtree(NODE **root) {
    if (*root == NULL) return;

    _delete_subtree(&((*root)->left));
    _delete_subtree(&((*root)->right));

    free(*root);
    *root = NULL; // 삭제 후 포인터 초기화
}

static int leaf_count(NODE *root) {
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return leaf_count(root->left) + leaf_count(root->right);
}

static int BST_leafcnt(TREE *pTree) {
    return leaf_count(pTree->root);
}

void BST_deletesub(TREE *pTree, int key) {
    if (pTree->root == NULL) return;

    if (pTree->root->data == key) { // 루트가 삭제 대상인 경우
        _delete_subtree(&(pTree->root));
        pTree->root = NULL;
        return;
    }

    NODE *parent = NULL, *target = pTree->root;
    NODE *queue[1000]; // 임시 큐
    int front = 0, rear = 0;

    queue[rear++] = pTree->root;

    // BFS로 삭제 대상 노드와 부모 노드 탐색
    while (front < rear) {
        NODE *current = queue[front++];
        if (current->left) {
            if (current->left->data == key) {
                parent = current;
                target = current->left;
                break;
            }
            queue[rear++] = current->left;
        }
        if (current->right) {
            if (current->right->data == key) {
                parent = current;
                target = current->right;
                break;
            }
            queue[rear++] = current->right;
        }
    }

    if (parent == NULL) return; // 삭제 대상 없음

    if (parent->left == target)
        parent->left = NULL;
    else if (parent->right == target)
        parent->right = NULL;

    _delete_subtree(&target);
}

void BST_destroy(TREE *pTree) {
    _delete_subtree(&(pTree->root));
    free(pTree);
}

int main(void) {
    int n, value, k;
    TREE *BST = BST_create();
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        BST_insert(BST, value, i);
    }

    scanf("%d", &k);
    BST_deletesub(BST, k);

    printf("%d", BST_leafcnt(BST));
    BST_destroy(BST);
    return 0;
}
