import sys
input = sys.stdin.readline

N, P, Q, X, Y = map(int, input().split())
dp = {}
dp[0] = 1

def solution(n:int):
    if n <= 0 :
        return 1
    elif n in dp:
        return dp[n]
    else :
        dp[n] = solution(n // P - X) + solution(n // Q - Y)
        return dp[n]

print(solution(N))