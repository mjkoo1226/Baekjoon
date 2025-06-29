#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int main(void){
    int n;
    scanf("%d", &n);

    int matrix[n][2];
    int dp[n][n];

    for (int i = 0; i < n; i++){
        scanf("%d %d", &matrix[i][0], &matrix[i][1]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = 2100000000;
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1];
                if (dp[i][j] > cost) dp[i][j] = cost;
            }
        }
    }

    printf("%d", dp[0][n - 1]);

    return 0;
}