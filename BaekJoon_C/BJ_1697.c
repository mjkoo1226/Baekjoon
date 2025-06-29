#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

typedef struct NODE {
    int data;
    int time;
    struct NODE *next;
} NODE;

typedef struct QUEUE {
    int cnt;
    NODE *head;
    NODE *tail;
} QUEUE;

NODE *createNode(int data, int time) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (!newnode) return NULL;
    newnode->next = NULL;
    newnode->data = data;
    newnode->time = time;
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

void push_queue(QUEUE *pqueue, int data, int time) {
    NODE *new = createNode(data, time);
    if (!new) return;

    if (pqueue->cnt == 0)
        pqueue->head = new;
    else
        pqueue->tail->next = new;
    pqueue->tail = new;
    pqueue->cnt++;
}

void pop_queue(QUEUE *pqueue, int *out, int *time) {
    if (pqueue->cnt == 0) return;
    NODE *target = pqueue->head;

    *out = target->data;
    *time = target->time;
    pqueue->head = target->next;
    pqueue->cnt--;

    if (pqueue->cnt == 0)
        pqueue->tail = NULL;

    free(target);
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int visited[MAX] = {0};

    QUEUE *q = createQueue();
    push_queue(q, n, 0);
    visited[n] = 1;

    int ans = 0;
    int now, next1, next2, next3, time;

    while (q->cnt > 0) {
        pop_queue(q, &now, &time);

        if (now == k) {
            ans = time;
            break;
        }

        next1 = now * 2;
        next2 = now - 1;
        next3 = now + 1;

        if (next1 < MAX && !visited[next1]) {
            push_queue(q, next1, time + 1);
            visited[next1] = 1;
        }

        if (next2 >= 0 && !visited[next2]) {
            push_queue(q, next2, time + 1);
            visited[next2] = 1;
        }

        if (next3 < MAX && !visited[next3]) {
            push_queue(q, next3, time + 1);
            visited[next3] = 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
