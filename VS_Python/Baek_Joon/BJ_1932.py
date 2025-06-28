import sys
input = sys.stdin.readline

n = int(input())

tri = [list(map(int, input().split())) for _ in range(n)]

dp = [[0] * n for _ in range(n)]
dp[0][0] = tri[0][0]

for i in range(1, n):
    for j in range(i + 1):
        if j == 0:
            dp[i][j] = dp[i - 1][j] + tri[i][j]
        elif j == i: 
            dp[i][j] = dp[i - 1][j - 1] + tri[i][j]
        else:
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j]

print(max(dp[n - 1]))