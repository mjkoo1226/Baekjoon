import sys
from collections import deque, defaultdict
input = sys.stdin.readline

n = int(input())
tree = defaultdict(list)

for _ in range(n - 1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

parents = [0] * (n + 1)
visited = [False] * (n + 1)

def bfs(root):
    queue = deque([root])
    visited[root] = True
    while queue:
        current = queue.popleft()
        for child in tree[current]:
            if not visited[child]:
                parents[child] = current
                visited[child] = True
                queue.append(child)

bfs(1)

for i in range(2, n + 1):
    print(parents[i])
