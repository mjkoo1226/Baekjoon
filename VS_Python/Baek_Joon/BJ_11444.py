MOD = 1000000007

def matrix_multiplier(A, B):
    return [[(A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD,
             (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD],
            [(A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD,
             (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD]]

def matrix_power(M, power):
    result = [[1, 0], [0, 1]]
    while power > 0:
        if power % 2 == 1:
            result = matrix_multiplier(result, M)
        M = matrix_multiplier(M, M)
        power //= 2
    return result[0][0]

def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    F = [[1, 1], [1, 0]]
    return matrix_power(F, n-1)

n = int(input())
print(fibonacci(n))