import sys
input = sys.stdin.readline

MOD = 1000000007
dp = [0] * 2501
dp[0] = 1

def gwalho(n):
    global dp
    if n == 0 or dp[n] != 0:
        return dp[n]
    else:
        for i in range(n):
            dp[n] += gwalho(i) * gwalho(n - 1 - i)
        dp[n] %= MOD
        return dp[n]
        
t = int(input())

for _ in range(t):
    n = int(input())
    if n % 2 != 0:
        print(0)
    else:
        print(gwalho(n // 2))