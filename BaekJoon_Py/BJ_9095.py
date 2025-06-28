import sys
input = sys.stdin.readline

t = int(input())

dp = {}
dp[0] = 0
dp[1] = 1
dp[2] = 2
dp[3] = 4

def sumsum(k:int):
    if k in dp:
        return dp[k]
    else :
        total = 0
        total = sumsum(k-1) + sumsum(k-2) + sumsum(k-3)
        dp[k] = total
        return dp[k]

for _ in range(t):
    n = int(input())
    print(sumsum(n))





