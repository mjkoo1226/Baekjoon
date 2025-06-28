import sys
input = sys.stdin.readline

n, b = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]

def matrixgop(arr1, arr2, size):
    answer = []

    for i in range(size):
        arr = arr1[i]
        result = []
        for j in range(size):
            hap = 0
            for k in range(size):
                hap += arr[k] * arr2[k][j]
            result.append(hap % 1000)
        answer.append(result)

    return answer

def square(a, k):
    global n

    if k == 1:
        return [[x % 1000 for x in row] for row in a]
    elif k % 2 == 1:
        return matrixgop(a, square(a, k - 1), n)
    else:
        half = square(a, k // 2)
        return matrixgop(half, half, n)
    
answer = square(matrix, b)
for row in answer:
    print(*row)