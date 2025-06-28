from collections import deque

a, b = map(int, input().split())
queue = deque()
queue.append((a, 1))  # (값, 연산 횟수)

while queue:
    x, cnt = queue.popleft()

    if x == b:
        print(cnt)
        break
    if x * 2 <= b:
        queue.append((x * 2, cnt + 1))
    if x * 10 + 1 <= b:
        queue.append((x * 10 + 1, cnt + 1))
else:
    print(-1)
