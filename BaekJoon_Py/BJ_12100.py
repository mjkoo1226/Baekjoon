import copy 

def move(board, direction):
    n = len(board)
    new_board = [[0]*n for _ in range(n)]

    for i in range(n):
        merged = [False] * n

        line = []
        for j in range(n):
            if direction == 'up':
                val = board[j][i]
            elif direction == 'down':
                val = board[n-1-j][i]
            elif direction == 'left':
                val = board[i][j]
            elif direction == 'right':
                val = board[i][n-1-j]
            if val != 0:
                line.append(val)

        result = []
        idx = 0
        
        while idx < len(line):
            if idx+1 < len(line) and line[idx] == line[idx+1]:
                result.append(line[idx]*2)
                idx += 2
            else:
                result.append(line[idx])
                idx += 1
        while len(result) < n:
            result.append(0)

        for j in range(n):
            if direction == 'up':
                new_board[j][i] = result[j]
            elif direction == 'down':
                new_board[n-1-j][i] = result[j]
            elif direction == 'left':
                new_board[i][j] = result[j]
            elif direction == 'right':
                new_board[i][n-1-j] = result[j]
                
    return new_board


def get_max_block(board):
    return max(map(max, board))

def dfs(board, depth):
    global answer
    if depth == 5:
        answer = max(answer, get_max_block(board))
        return
    
    for d in ['up', 'down', 'left', 'right']:
        next_board = move(copy.deepcopy(board), d)
        dfs(next_board, depth + 1)

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]

answer = 0
dfs(board, 0)

print(answer)
