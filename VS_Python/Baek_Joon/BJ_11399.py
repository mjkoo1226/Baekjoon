import sys
input = sys.stdin.readline

n = int(input())
time = list(map(int, input().split()))

time.sort()

total = 0
for i in range(n):
    for j in range(i+1):
        total += time[j]

print(total)