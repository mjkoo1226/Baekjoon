from collections import deque

N, M = map(int, input().split())
board = [list(map(int, list(input()))) for _ in range(N)]

visited = [[[0] * 2 for _ in range(M)] for _ in range(N)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs():
    queue = deque()
    queue.append((0, 0, 1))
    visited[0][0][1] = 1
    
    while queue:
        x, y, smash = queue.popleft()
        
        if x == M - 1 and y == N - 1:
            return visited[y][x][smash]
        
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            
            if 0 <= nx < M and 0 <= ny < N:
                if board[ny][nx] == 0 and visited[ny][nx][smash] == 0:
                    visited[ny][nx][smash] = visited[y][x][smash] + 1
                    queue.append((nx, ny, smash))
                
                elif board[ny][nx] == 1 and smash == 1 and visited[ny][nx][0] == 0:
                    visited[ny][nx][0] = visited[y][x][1] + 1
                    queue.append((nx, ny, 0))
    
    return -1

print(bfs())
