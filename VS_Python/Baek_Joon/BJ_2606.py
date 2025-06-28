import sys
input = sys.stdin.readline

n = int(input())
t = int(input())

com = list(0 for i in range(n+1))
a = [0] * t
b = [0] * t
com[1] = 1

for i in range(t):
    a[i], b[i] = map(int, input().split())

for i in range(n):
    for j in range(t):
        if com[a[j]] > 0:
            com[b[j]] = 1
        elif com[b[j]] > 0:
            com[a[j]] = 1

count = 0
for i in range(n+1):
    if com[i] == 1:
        count += 1

print(count - 1)
