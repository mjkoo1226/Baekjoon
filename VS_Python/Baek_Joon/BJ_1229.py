# 시간초과 해결을 못해서 포기

import sys
input = sys.stdin.readline

n = int(input())
hex_num = [1]
index = 0

while hex_num[index] <= n:
    new_num = hex_num[index] + (4 * index + 5)
    hex_num.append(new_num)
    index += 1

def mincount(N:int):
    dp = {}
    dp[0] = 0
    
    for i in hex_num:
        for j in range(i, N + 1):
            if j in dp:
                dp[j] = min(dp[j], dp[j - i] + 1)
            else :
                dp[j] = dp[j - i] + 1
    
    return dp[N]

print(mincount(n))

