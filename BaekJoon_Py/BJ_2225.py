import sys
input = sys.stdin.readline

N, K = map(int, input().split())

dp = dict()
dp[(0, 0)] = 1

for i in range(1, N + 1):
    dp[(i, 0)] = 0
    dp[(i, 1)] = 1

def sumsum(n:int, k:int):
    if (n, k) in dp:
        return dp[(n, k)]
    else :
        total = 0
        for i in range(n + 1):
            total += sumsum(n - i, k - 1)
        dp[(n, k)] = total % 1000000000
        return dp[(n, k)]

print(sumsum(N, K))