# import sys
# sys.setrecursionlimit(100005)
# input = sys.stdin.readline

# left = {}
# right = {}

# n = int(input())
# root = 1

# for i in range(n):
#     A, B, C = map(int,input().split())

#     left[A] = B
#     right[A] = C

# def countright(node):
#     if right[node] != -1:        
#         return countright(right[node]) + 1
#     return 0

# print(2 * (n - 1) - countright(1))

import sys
input = sys.stdin.readline
sys.setrecursionlimit(100005)

left = {}
right = {}

n = int(input())

for i in range(n):
    A, B, C = input().split()

    left[A] = B
    right[A] = C

cnt = 0

def countright(node):
    global cnt

    if right[node] != '-1':
        cnt += 1
        countright(right[node])
    return

countright('1')
print(2 * (n - 1) - cnt)