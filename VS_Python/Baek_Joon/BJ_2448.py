import sys
input = sys.stdin.readline

k = int(input())
inorder = list(map(int, input().split()))

lev = list([] for _ in range(k))

def addtree(ino, n):
    if not ino:
        return
    
    mid = len(ino) // 2
    root = ino[mid]

    lev[n].append(root)

    addtree(ino[:mid], n + 1)
    addtree(ino[mid + 1:], n + 1)

addtree(inorder, 0)

for level in lev:
    print(*level)
