#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define HASH_SIZE 1000003
#define MAX_N 21

bool visited[11][HASH_SIZE];

uint64_t hash_board(int board[MAX_N][MAX_N], int n) {
    uint64_t h = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            h = h * 31 + board[i][j];
    return h % HASH_SIZE;
}

int n, answer = 0;

int dx[4] = {-1, 1, 0, 0}; // up, down, left, right
int dy[4] = {0, 0, -1, 1};

enum { UP, DOWN, LEFT, RIGHT };

void copy_board(int dest[MAX_N][MAX_N], int src[MAX_N][MAX_N]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dest[i][j] = src[i][j];
}

int get_max_block(int board[MAX_N][MAX_N]) {
    int max_val = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] > max_val)
                max_val = board[i][j];
    return max_val;
}

int max(int a, int b) {
    return a > b ? a : b;
}

// 0: 계속 진행 가능, 1: 합칠 게 없음, 2: 더 이상 발전 불가
int pruning(int board[MAX_N][MAX_N]) {
    int check[2025] = {0};
    int cnt = 0, key = 1, max_val = 0, sum_rest = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = board[i][j];
            if (k == 0) continue;

            if (check[k] > 0) 
                key = 0;
            check[k] += 1;

            cnt++;
        }
    }

    // max_val 및 sum_rest 계산
    int k = 4048;

    for (int i = 0; i < 11; i++) {
        k /= 2;
        if (check[k] > 0) {
            if (max_val == 0) max_val = k;
            else sum_rest += k * check[k];
        }
    }

    if (max_val > sum_rest)
        return 2;
    
    return key;
}

void move(int board[MAX_N][MAX_N], int direction, int result[MAX_N][MAX_N]) {
    memset(result, 0, sizeof(int) * MAX_N * MAX_N);

    for (int i = 0; i < n; i++) {
        int line[MAX_N] = {0};
        int len = 0;

        // 1. 현재 줄을 방향에 맞게 1차원 배열로 추출
        for (int j = 0; j < n; j++) {
            int val = 0;
            if (direction == UP)
                val = board[j][i];
            else if (direction == DOWN)
                val = board[n - 1 - j][i];
            else if (direction == LEFT)
                val = board[i][j];
            else if (direction == RIGHT)
                val = board[i][n - 1 - j];

            if (val != 0)
                line[len++] = val;
        }

        // 2. 병합 로직 (한 번만 합쳐지도록)
        int temp[MAX_N] = {0};
        int t = 0, idx = 0;
        while (idx < len) {
            if (idx + 1 < len && line[idx] == line[idx + 1]) {
                temp[t++] = line[idx] * 2;
                idx += 2;
            } else {
                temp[t++] = line[idx];
                idx += 1;
            }
        }

        // 3. 결과 보드에 다시 채우기
        for (int j = 0; j < n; j++) {
            int v = (j < t) ? temp[j] : 0;
            if (direction == UP)
                result[j][i] = v;
            else if (direction == DOWN)
                result[n - 1 - j][i] = v;
            else if (direction == LEFT)
                result[i][j] = v;
            else if (direction == RIGHT)
                result[i][n - 1 - j] = v;
        }
    }
}


int is_same(int a[MAX_N][MAX_N], int b[MAX_N][MAX_N]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j]) return 0;
    return 1;
}

void dfs(int board[MAX_N][MAX_N], int depth, int n) {
    if (depth == 10 || pruning(board) == 2) {
        answer = max(answer, get_max_block(board));
        return;
    }

    uint64_t h = hash_board(board, n);
    if (visited[depth][h]) return;
    visited[depth][h] = true;

    for (int d = 0; d < 4; d++) {
        int next_board[MAX_N][MAX_N];
        move(board, d, next_board);

        if (!is_same(board, next_board))
            dfs(next_board, depth + 1, n);
    }
}

int main() {
    scanf("%d", &n);
    int board[MAX_N][MAX_N];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &board[i][j]);

    dfs(board, 0, n);

    printf("%d\n", answer);
    return 0;
}
