import sys
input = sys.stdin.readline

N, P, Q = map(int, input().split())
dp = {}
dp[0] = 1

def solution(n:int):
    if n in dp:
        return dp[n]
    else :
        dp[n] = solution(n // P) + solution(n // Q)
        return dp[n]

print(solution(N))