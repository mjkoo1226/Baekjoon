import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort(reverse=True)
score = 0

for i in range(n):
    for j in range(n):
        if A[i] > B[j] != 0:
            score += 2
            A[i] = 0
            B[j] = 0
            break

for i in range(n):
    if A[i] != 0:
        for j in range(n):
            if A[i] == B[j] and B[j] != 0:
                score += 1
                B[j] = 0
                break

print(score)