import sys
input = sys.stdin.readline

answer = 0
N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

def get_max_block(board):
    return max(map(max, board))

answer = get_max_block(board)
max_list = [0] * 11

def move(board, direction):
    n = len(board)

    if direction == 0:  # up
        for col in range(n):
            top = 0
            last = 0
            for row in range(n):
                val = board[row][col]
                if val == 0:
                    continue
                board[row][col] = 0
                if last == val:
                    board[top - 1][col] *= 2
                    last = 0
                else:
                    board[top][col] = val
                    last = val
                    top += 1

    elif direction == 1:  # down
        for col in range(n):
            top = n - 1
            last = 0
            for row in range(n - 1, -1, -1):
                val = board[row][col]
                if val == 0:
                    continue
                board[row][col] = 0
                if last == val:
                    board[top + 1][col] *= 2
                    last = 0
                else:
                    board[top][col] = val
                    last = val
                    top -= 1

    elif direction == 2:  # left
        for row in range(n):
            top = 0
            last = 0
            for col in range(n):
                val = board[row][col]
                if val == 0:
                    continue
                board[row][col] = 0
                if last == val:
                    board[row][top - 1] *= 2
                    last = 0
                else:
                    board[row][top] = val
                    last = val
                    top += 1

    elif direction == 3:  # right
        for row in range(n):
            top = n - 1
            last = 0
            for col in range(n - 1, -1, -1):
                val = board[row][col]
                if val == 0:
                    continue
                board[row][col] = 0
                if last == val:
                    board[row][top + 1] *= 2
                    last = 0
                else:
                    board[row][top] = val
                    last = val
                    top -= 1

def dfs(board, depth):
    global answer, max_list
    
    max_num = get_max_block(board)
    if (max_num <= max_list[depth]): return

    answer = max(answer, max_num)
    k = answer
    
    if depth == 10 :
        if k > max_list[depth]:
            for i in range(depth, 0, -1):
                if k > max_list[i]:
                    max_list[i] = k
                k //= 2
        return

    backup = [row[:] for row in board]
    for d in range(4):
        move(board, d)
        if backup == board:
            continue
        dfs(board, depth + 1)
        board = [row[:] for row in backup]

dfs(board, 0)

print(answer)
