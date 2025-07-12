import sys
from collections import defaultdict, deque

input = sys.stdin.readline

n = int(input())
tree = defaultdict(list)

for _ in range(n):
    arr = list(map(int, input().split()))
    a = arr[0]
    for i in range(len(arr) // 2 - 1):
        b = arr[2 * i + 1]
        d = arr[2 * i + 2]
        tree[a].append((b, d))
        tree[b].append((a, d))

def bfs(start):
    visited = [-1] * (n + 1)
    visited[start] = 0
    q = deque([start])
    max_dist = 0
    max_node = start

    while q:
        current = q.popleft()
        for neighbor, dist in tree[current]:
            if visited[neighbor] == -1:
                visited[neighbor] = visited[current] + dist
                q.append(neighbor)
                if visited[neighbor] > max_dist:
                    max_dist = visited[neighbor]
                    max_node = neighbor
    return max_node, max_dist

node_far, _ = bfs(1)
_, diameter = bfs(node_far)

print(diameter)
