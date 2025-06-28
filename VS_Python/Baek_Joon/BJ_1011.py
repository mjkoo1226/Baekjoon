import sys, math
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    start, end = map(int, input().split())
    distance = end - start
    
    n = int(math.sqrt(distance))
    cnt = 2 * n - 1
    distance -= n * n
    
    for i in range(n, 0, -1):
        k = distance // i
        cnt += k
        distance -= i * k
            
    print(cnt)
    
    