#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
    struct NODE *left;
    struct NODE *right;
    char data;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *rear;
    Node *index;
    int cnt;
} LinkedList;

LinkedList* makeList() {
    LinkedList* newlist = (LinkedList*)malloc(sizeof(LinkedList));
    newlist->cnt = 0;
    newlist->head = NULL;
    newlist->rear = NULL;
    newlist->index = NULL;
    return newlist;
}

Node *createNode(char data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insertList(Node *newnode, LinkedList *list) {
    if (!newnode || !list || !list->index) return;

    Node* pre = list->index->left;

    newnode->right = list->index;
    list->index->left = newnode;
    newnode->left = pre;

    if (pre) pre->right = newnode;
    else list->head = newnode;

    if (list->index == list->rear->right)
        list->rear = newnode;

    list->cnt++;
}

void deleteNode(LinkedList *list) {
    if (!list || !list->index || !list->index->left) return;

    Node *target = list->index->left;
    Node *pre = target->left;

    if (pre)
        pre->right = list->index;
    else
        list->head = list->index;

    list->index->left = pre;

    free(target);
    list->cnt--;
}

void printList(LinkedList *list) {
    Node *pLoc = list->head;
    while (pLoc != NULL && pLoc->data != '\0') {
        printf("%c", pLoc->data);
        pLoc = pLoc->right;
    }
}

void cmd(LinkedList *list, char a, char b) {
    if (a == 'L') {
        if (list->index->left)
            list->index = list->index->left;
    } else if (a == 'D') {
        if (list->index->right)
            list->index = list->index->right;
    } else if (a == 'B') {
        deleteNode(list);
    } else if (a == 'P') {
        Node *newnode = createNode(b);
        insertList(newnode, list);
    }
}

int main(void) {
    int n;
    char str[100001], input1, input2;
    LinkedList *list = makeList();

    list->index = createNode('\0');
    list->head = list->index;
    list->rear = list->index;

    scanf("%s", str);
    for (int i = 0; i < (int)strlen(str); i++) {
        Node *newnode = createNode(str[i]);
        insertList(newnode, list);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        input2 = '\0';
        scanf(" %c", &input1);
        if (input1 == 'P') {
            scanf(" %c", &input2);
        }
        cmd(list, input1, input2);
    }

    printList(list);

    return 0;
}
