import sys
input = sys.stdin.readline

t= int(input())

for _ in range(t):
    A, B = input().split()
    if len(A) != len(B):
        print("-1")
        continue

    count = 0
    A_index = []
    B_index = []

    for i in range(len(A)):
        if A[i] == 'a':
            A_index.append(i)
        if B[i] == 'a':
            B_index.append(i)
    
    for i in range(len(A_index)):
        count += abs(A_index[i] - B_index[i])
    
    print(count)