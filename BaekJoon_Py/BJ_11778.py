import math

MOD = 1000000007

def matrix_mult(arr1, arr2):
    result = [[0, 0], [0, 0]]
    
    result[0][0] = (arr1[0][0] * arr2[0][0] + arr1[0][1] * arr2[1][0]) % MOD
    result[0][1] = (arr1[1][0] * arr2[0][0] + arr1[1][1] * arr2[1][0]) % MOD
    result[1][0] = (arr1[0][0] * arr2[0][1] + arr1[0][1] * arr2[1][1]) % MOD
    result[1][1] = (arr1[1][0] * arr2[0][1] + arr1[1][1] * arr2[1][1]) % MOD

    return result

def matrix_pow(mat, n):
    res = [[1, 0], [0, 1]]
    while n > 0:
        if n % 2 == 1:
            res = matrix_mult(res, mat)
        mat = matrix_mult(mat, mat)
        n //= 2
    return res

def fib(n):
    if n == 0:
        return 0
    base = [[1, 1], [1, 0]]
    return matrix_pow(base, n)[0][1]
        
n, m = map(int, input().split())
k = math.gcd(n, m)
print(fib(k))

