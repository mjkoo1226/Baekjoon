#include <stdio.h>
#include <stdlib.h>


typedef struct DOT
{
    int x;
    int y;
    int z;
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

NODE *createNode(int x, int y, int z){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (!newnode) return NULL;

    newnode->next = NULL;
    newnode->data.x = x;
    newnode->data.y = y;
    newnode->data.z = z;

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


void push_queue(QUEUE *pqueue, int x, int y, int z){
    NODE *new = createNode(x, y, z);
    if (!new) return;

    if (pqueue->cnt == 0)
        pqueue->head = new;
    else
        pqueue->tail->next = new;
    pqueue->tail = new;
    pqueue->cnt++;
}

void pop_queue(QUEUE *pqueue, int *x, int *y, int *z){
    if (pqueue->cnt == 0) return;

    NODE *target = pqueue->head;
    
    pqueue->head = target->next;
    pqueue->cnt--;
    *x = target->data.x;
    *y = target->data.y;
    *z = target->data.z;

    free(target);
}

int main(void){
    int n, m, h, ans = 0;
    scanf(" %d %d %d", &m, &n, &h);

    int grid[n][m][h];
    int check[n][m][h];

    int dx[] = {-1, 1, 0, 0, 0, 0};
    int dy[] = {0, 0, -1, 1, 0, 0};
    int dz[] = {0, 0, 0, 0, -1, 1};

    QUEUE *q = createQueue();

    for(int k = 0; k < h; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &grid[i][j][k]); 
                check[i][j][k] = 0;

                if (grid[i][j][k] == 1) {
                    push_queue(q, i, j, k);
                }
            }
        }
    }
    

    while(q->cnt > 0){
        int x, y, z;
        pop_queue(q, &x, &y, &z);

        for (int d = 0; d < 6; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            int nz = z + dz[d];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
            if (grid[nx][ny][nz] != 0) continue;
            if (check[nx][ny][nz] != 0) continue;

            check[nx][ny][nz] = check[x][y][z] + 1;
            grid[nx][ny][nz] = 1;
            push_queue(q, nx, ny, nz);
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < h; k++){
                if (grid[i][j][k] == 0) {
                    ans = -1;
                    break;
                }
                if (check[i][j][k] > ans)
                    ans = check[i][j][k];
            }
            if (ans == -1) break;
        }
        if (ans == -1) break;
    }

    printf("%d", ans);

    return 0;
}