#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}NODE;

typedef struct STACK
{
    int cnt;
    NODE *head;
}STACK;

typedef struct QUEUE
{
    int cnt;
    NODE *head;
    NODE *tail;
}QUEUE;

NODE *createNode(int data){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (!newnode) return NULL;

    newnode->next = NULL;
    newnode->data = data;

    return newnode;
}

STACK *createStack(){
    STACK *newstack = (STACK*)malloc(sizeof(STACK));
    if (!newstack) return NULL;

    newstack->cnt = 0;
    newstack->head = NULL;

    return newstack;
}

QUEUE *createQueue(){
    QUEUE *newqueue = (QUEUE*)malloc(sizeof(QUEUE));
    if (!newqueue) return NULL;

    newqueue->cnt = 0;
    newqueue->tail = NULL;
    newqueue->head = NULL;

    return newqueue;
}

void push_stack(STACK *pstack, int data){
    NODE *new = createNode(data);
    if (!new) return;
    
    new->next = pstack->head;
    pstack->head = new;
    pstack->cnt++;
}

void push_queue(QUEUE *pqueue, int data){
    NODE *new = createNode(data);
    if (!new) return;

    if (pqueue->cnt == 0)
        pqueue->head = new;
    else
        pqueue->tail->next = new;
    pqueue->tail = new;
    pqueue->cnt++;
}

void pop_stack(STACK *pstack, int *out){
    if (pstack->cnt == 0) return;
    
    NODE *target = pstack->head;

    pstack->head = target->next;
    pstack->cnt--;
    *out = target->data;
    free(target);
}

void pop_queue(QUEUE *pqueue, int *out)
{
    if (pqueue->cnt == 0) return;

    NODE *target = pqueue->head;
    
    pqueue->head = target->next;
    pqueue->cnt--;
    *out = target->data;

    free(target);
}

int is_fin(char *list, int len){
    for(int i = 0; i < len; i++){
        if (list[i] == 1) return 0;
    }
    return 1;
}

int main(void){
    int v, e, start;
    scanf("%d %d %d", &v, &e, &start);
    char edge[v][v];
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            edge[i][j] = 1;
        }
    }
    for(int i = 0; i < e; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a - 1][b - 1] = 2;
        edge[b - 1][a - 1] = 2;
    }

    STACK *stack = createStack();
    QUEUE *queue = createQueue();

    char dfs_check[v];
    char bfs_check[v];

    for(int i = 0; i < v; i++){
        dfs_check[i] = 1;
        bfs_check[i] = 1;
    }

    int next = start;
    int present = start;
    
    while (1) {
        present = next;

        if (dfs_check[present - 1] == 1) {
            printf("%d ", present);
            dfs_check[present - 1] = 2;

            for(int i = v - 1; i >= 0; i--){
                if(edge[present - 1][i] == 2 && dfs_check[i] == 1){
                    push_stack(stack, i + 1);
                }
            }
        }

        if (stack->cnt == 0) break;

        pop_stack(stack, &next);
    }

    printf("\n");

    next = start;
    while (1) {
        present = next;

        if (bfs_check[present - 1] == 1) {
            printf("%d ", present);
            bfs_check[present - 1] = 2;

            for(int i = 0; i < v; i++){
                if(edge[present - 1][i] == 2 && bfs_check[i] == 1){
                    push_queue(queue, i + 1);
                }
            }
        }

        if (queue->cnt == 0) break;

        pop_queue(queue, &next);
    }

    return 0;
}