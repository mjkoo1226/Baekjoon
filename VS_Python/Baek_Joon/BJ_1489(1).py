import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort()

score = 0

index_A_top = n - 1
index_A_bottom = 0
index_B_top = n - 1
index_B_bottom = 0

while index_A_top >= index_A_bottom and index_B_top >= index_B_bottom :
    if A[index_A_top] > B[index_B_top] :
        score += 2
        index_A_top -= 1
        index_B_top -= 1
    elif A[index_A_top] < B[index_B_top] :
        index_B_top -= 1
        index_A_bottom += 1
    else :
        if index_A_top == index_A_bottom or index_B_top == index_B_bottom:
            score += 1
            break
        else :
            if A[index_A_top - 1] < B[index_B_top - 1] :
                score += 2
                index_A_top -= 1
                index_A_bottom += 1
                index_B_top -= 2
            elif A[index_A_top - 1] > B[index_B_top - 1] : 
                score += 3
                index_A_top -= 2
                index_B_top -= 2
            else :
                index_B_top -= 1
                index_A_bottom += 1

print(score)
    