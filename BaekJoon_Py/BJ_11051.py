import sys
sys.setrecursionlimit(30000)

n, k = map(int, input().split())

if k > n // 2:
    k = n - k

MOD = 10007

def fac2(n, k):
    if n == 1 or k == 0:
        return 1
    else:
        total = n * fac2(n - 1, k - 1)
        return total

answer = fac2(n, k) // fac2(k, k)
answer %= MOD

print(answer)