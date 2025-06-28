import sys
input = sys.stdin.readline

MOD = 1000000000
I = [[1, 0], [0, 1]]
START, END = map(int, input().split())

total = 0

def matrix_gop(a, b):
    result = [[0, 0], [0 ,0]]
    
    result[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD
    result[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD
    result[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD
    result[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD
    
    return result

def matrix_exp(a, n):
    if n == 1:
        return matrix_gop(a, I)
    elif n % 2 == 1:
        return matrix_gop(a, matrix_exp(a, n - 1))
    else:
        half = matrix_exp(a, n // 2)
        return matrix_gop(half, half)

a = [[1, 1], [1, 0]]
b = matrix_exp(a, END + 2)
c = matrix_exp(a, START + 1)
print((b[0][1] - c[0][1] + MOD) % MOD)