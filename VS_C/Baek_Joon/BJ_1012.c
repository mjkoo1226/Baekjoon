#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
    int t;
    scanf("%d", &t);
    for(int test = 0; test < t; test++){
        int n, m, k;
        scanf(" %d %d %d", &n, &m, &k);

        int grid[n][m];
        int check[n][m];

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        DOT baechu[k];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                check[i][j] = 0;
                grid[i][j] = 0;
            }
        }

        for (int i = 0; i < k; i++) {
            int x, y;
            scanf("%d %d", &x, &y); 

            baechu[i].x = x;
            baechu[i].y = y;

            grid[x][y] = 1;
        }

        int cnt = 0;

        for(int i = 0; i < k; i++){
            int a, b;
            
            a = baechu[i].x;
            b = baechu[i].y;

            if (check[a][b] != 0) 
                continue;
            
            check[a][b] = 1;
            cnt++;

            QUEUE *q = createQueue();
            
            push_queue(q, a, b);

            while(q->cnt > 0){
                int x, y;
                pop_queue(q, &x, &y);

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (grid[nx][ny] == 0) continue;
                    if (check[nx][ny] != 0) continue;

                    check[nx][ny] = 1;
                    push_queue(q, nx, ny);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}