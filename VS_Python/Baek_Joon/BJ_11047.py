import sys
input = sys.stdin.readline

n, k = map(int, input().split())
coin = [0] * n
for i in range(n):
    coin[i] = int(input())

coin.sort(reverse=True)
cnt = 0

for c in coin:
    if c <= k:  
        cnt += k // c 
        k %= c 

    if k == 0: 
        break

print(cnt)