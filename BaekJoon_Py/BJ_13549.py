from collections import deque

n, k = map(int, input().split())

MAX = 100001
visited = [False] * MAX
queue = deque()
queue.append((n, 0))

while queue:
    x, time = queue.popleft()
    if x == k:
        print(time)
        break
    if visited[x]:
        continue
    visited[x] = True
    if 0 <= 2 * x < MAX and not visited[2 * x]:
        queue.appendleft((2 * x, time))
    if 0 <= x - 1 < MAX and not visited[x - 1]:
        queue.append((x - 1, time + 1))
    if 0 <= x + 1 < MAX and not visited[x + 1]:
        queue.append((x + 1, time + 1))