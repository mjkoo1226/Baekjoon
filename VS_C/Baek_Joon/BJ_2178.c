#include <stdio.h>
#include <stdlib.h>

typedef struct DOT{
    int x;
    int y;
}DOT;

typedef struct NODE
{
    DOT data;
    struct NODE *next;
}NODE;

typedef struct QUEUE
{
    int cnt;
    NODE *head;
    NODE *tail;
}QUEUE;

NODE *createNode(int x, int y){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (!newnode) return NULL;

    newnode->next = NULL;
    newnode->data.x = x;
    newnode->data.y = y;

    return newnode;
}

QUEUE *createQueue(){
    QUEUE *newqueue = (QUEUE*)malloc(sizeof(QUEUE));
    if (!newqueue) return NULL;

    newqueue->cnt = 0;
    newqueue->tail = NULL;
    newqueue->head = NULL;

    return newqueue;
}


void push_queue(QUEUE *pqueue, int x, int y){
    NODE *new = createNode(x, y);
    if (!new) return;

    if (pqueue->cnt == 0)
        pqueue->head = new;
    else
        pqueue->tail->next = new;
    pqueue->tail = new;
    pqueue->cnt++;
}

void pop_queue(QUEUE *pqueue, int *x, int *y){
    if (pqueue->cnt == 0) return;

    NODE *target = pqueue->head;
    
    pqueue->head = target->next;
    pqueue->cnt--;
    *x = target->data.x;
    *y = target->data.y;

    free(target);
}

int main(void){
    int n, m;
    scanf(" %d %d", &n, &m);

    int grid[n][m];
    int check[n][m];

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    QUEUE *q = createQueue();

    char line[101];

    for (int i = 0; i < n; i++) {
        scanf(" %s", line);

        for (int j = 0; j < m; j++) {
            grid[i][j] = line[j] - '0';
            check[i][j] = -1;
        }
    }

    check[0][0] = 1;
    push_queue(q, 0, 0);

    while (q->cnt > 0) {
        int x, y;
        pop_queue(q, &x, &y);

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == 0) continue;
            if (check[nx][ny] != -1) continue;

            check[nx][ny] = check[x][y] + 1;
            push_queue(q, nx, ny);
        }
    }


    printf("%d\n", check[n - 1][m - 1]);

    return 0;
}
