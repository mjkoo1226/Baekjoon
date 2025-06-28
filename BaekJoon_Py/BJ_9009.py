import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    
    dp = []
    a, b = 1, 1
    while a <= n:
        dp.append(a)
        a, b = b, a + b
    
    index = len(dp) - 1
    answer = []
    
    while(index > 0):
        if n >= dp[index]:
            n -= dp[index]
            answer.append(dp[index])
        else:
            index -= 1
    
    answer.sort()
    print(*answer)
        
