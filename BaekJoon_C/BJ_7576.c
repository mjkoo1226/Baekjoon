#include <stdio.h>
#include <stdlib.h>


typedef struct DOT
{
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
    int n, m, ans = 0;
    scanf(" %d %d", &m, &n);

    int grid[n][m];
    int check[n][m];

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    QUEUE *q = createQueue();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]); 
            check[i][j] = 0;

            if (grid[i][j] == 1) {
                push_queue(q, i, j);
            }
        }
    }

    while(q->cnt > 0){
        int x, y;
        pop_queue(q, &x, &y);

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] != 0) continue;
            if (check[nx][ny] != 0) continue;

            check[nx][ny] = check[x][y] + 1;
            grid[nx][ny] = 1; // 익은 상태로 변경
            push_queue(q, nx, ny);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (grid[i][j] == 0) {
                ans = -1;
                break;
            }
            if (check[i][j] > ans)
                ans = check[i][j];
        }
        if (ans == -1) break;
    }

    printf("%d", ans);

    return 0;
}