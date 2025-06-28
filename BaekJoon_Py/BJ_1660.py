import sys
input = sys.stdin.readline

n = int(input())
tri_num = [1]
index = 0

while tri_num[index] <= n:
    new_num = tri_num[index] + (index + 2) * (index + 3) // 2
    tri_num.append(new_num)
    index += 1

def mincount(N:int):
    dp = {}
    dp[0] = 0
    
    for i in tri_num:
        for j in range(i, N + 1):
            if j in dp:
                dp[j] = min(dp[j], dp[j - i] + 1)
            else :
                dp[j] = dp[j - i] + 1
    
    return dp[N]

print(mincount(n))

