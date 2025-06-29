#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
} NODE;

typedef struct QUEUE {
    int cnt;
    NODE *head;
    NODE *tail;
} QUEUE;

NODE *createNode(int data) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (!newnode) return NULL;

    newnode->next = NULL;
    newnode->data = data;

    return newnode;
}

QUEUE *createQueue() {
    QUEUE *newqueue = (QUEUE*)malloc(sizeof(QUEUE));
    if (!newqueue) return NULL;

    newqueue->cnt = 0;
    newqueue->head = NULL;
    newqueue->tail = NULL;
    
    return newqueue;
}

void push_queue(QUEUE *pqueue, int data) {
    NODE *new = createNode(data);
    if (!new) return;

    if (pqueue->cnt == 0)
        pqueue->head = new;
    else
        pqueue->tail->next = new;
    pqueue->tail = new;
    pqueue->cnt++;
}

void pop_queue(QUEUE *pqueue, int *out) {
    if (pqueue->cnt == 0) return;
    NODE *target = pqueue->head;

    *out = target->data;
    pqueue->head = target->next;
    pqueue->cnt--;

    if (pqueue->cnt == 0)
        pqueue->tail = NULL;

    free(target);
}

int main(){
    int v, e;
    scanf("%d %d", &v, &e);

    int arc[v][v];

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            arc[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arc[a - 1][b - 1] = 1;
        arc[b - 1][a - 1] = 1;
    }


    int visited[v], ans = 0;

    for (int i = 0; i < v; i++) {
        visited[i] = 0;
    }

    for (int s = 0; s < v; s++){

        if (visited[s] != 0) continue;
        visited[s] = 1;

        ans++;

        QUEUE *q = createQueue();
        push_queue(q, s);

        while (q->cnt > 0){
            int temp;
            pop_queue(q, &temp);

            for(int i = 0; i < v; i++){
                if (arc[temp][i] == 1 && visited[i] == 0){
                    visited[i] = 1;
                    push_queue(q, i);
                }
            }
        }
    }

    printf("%d", ans);
    
    return 0;
}