R, C = map(int, input().split())

map = [None] * R
for i in range(R):
    map[i] = list(input())
    for j in range(C):
        map[i][j] = ord(map[i][j]) - 64
    
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

ans = 1
visited = [0] * 27

def dfs(x: int, y: int, depth: int):
    global ans
    ans = max(ans, depth)

    for d in range(4):
        nx, ny = x + dx[d], y + dy[d]
        if 0 <= nx < C and 0 <= ny < R:
            k = map[ny][nx]
            if visited[k] == 0:
                visited[k] = 1
                dfs(nx, ny, depth + 1)
                visited[k] = 0

visited[map[0][0]] = 1
dfs(0, 0, 1)

print(ans)