# 2023 Spring COSE102 Midterm Exam
# Q1

A = list(map(int, input()))
B = list(map(int, input()))

if len(A) < len(B):
    temp = A
    A = B
    B = temp

dic = {}

for i in range(len(A)):
    dic[A[i]] = i

B_order = list(0 for _ in range(len(B)))
key = 0

for i in range(len(B)):
    if B[i] in dic:
        B_order[i] = dic[B[i]]
        if i > 0:
           if B_order[i] < B_order[i-1]:
               key = 0
               break
        key = 1
    else:
        key = 0
        break

if key == 0:
    print("NO")
else:
    print("YES")