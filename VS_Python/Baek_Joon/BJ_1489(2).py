import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort(reverse=True)
B.sort(reverse=True)

score = 0

index_A = 0
index_B = 0

while index_A < n and index_B < n :
    if A[index_A] > B[index_B] :
        score += 2
        index_A += 1
        index_B += 1
    elif A[index_A] < B[index_B] :
        index_B += 1
    else :
        if index_A == n - 1 or index_B == n - 1:
            score += 1
            index_A += 1
            index_B += 1
        else :
            if A[index_A + 1] < B[index_B + 1] :
                score += 2
                index_A += 1
                index_B += 2
            elif A[index_A + 1] > B[index_B + 1] : 
                score += 1
                index_A += 1
                index_B += 1
            else :
                index_B += 1

print(score)
    