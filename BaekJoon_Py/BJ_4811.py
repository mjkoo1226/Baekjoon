import sys
input = sys.stdin.readline

dp = [0] * 31
dp[0] = 1
dp[1] = 1
dp[2] = 2

for i in range(2, 30):
    for j in range(i + 1):
        dp[i + 1] += dp[j] * dp[i - j]

while 1:
    n = int(input())
    if n == 0 : break
    else: print(dp[n])

