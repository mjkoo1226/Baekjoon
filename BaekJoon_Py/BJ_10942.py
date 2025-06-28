import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))

dp = [[0] * n for _ in range(n)]

for i in range(n):
    dp[i][i] = 1
    
for i in range(n - 1):
    if nums[i] == nums[i + 1]:
        dp[i][i + 1] = 1
    
for length in range(3, n + 1):
    for start in range(n - length + 1):
        end = start + length - 1
        if nums[start] == nums[end] and dp[start + 1][end - 1]:
            dp[start][end] = 1

t = int(input())
for _ in range(t):
    s, e = map(int, input().split())
    print(dp[s - 1][e - 1])