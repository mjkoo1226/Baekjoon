MOD = 1000000007

def matrix_mult(arr1, arr2):
    result = [[0, 0], [0, 0]]
    
    result[0][0] = (arr1[0][0] * arr2[0][0] + arr1[0][1] * arr2[1][0]) % MOD
    result[0][1] = (arr1[1][0] * arr2[0][0] + arr1[1][1] * arr2[1][0]) % MOD
    result[1][0] = (arr1[0][0] * arr2[0][1] + arr1[0][1] * arr2[1][1]) % MOD
    result[1][1] = (arr1[1][0] * arr2[0][1] + arr1[1][1] * arr2[1][1]) % MOD

    return result

def div_and_conq(arr, k):
    if k < 1:
        return [[1, 0], [0, 1]]
    if k == 1:
        return arr
    
    half = div_and_conq(arr, k // 2)
    half_squared = matrix_mult(half, half)
    
    if k % 2 == 0:
        return half_squared
    else:
        return matrix_mult(half_squared, arr)
        
n = int(input())

if n == 1:
    print(3)
elif n == 2:
    print(7)
else:
    arr = [[2, 1], [1, 0]]
    first = [[17, 7], [7, 3]]

    result = matrix_mult(div_and_conq(arr, n - 3), first)
    print(result[0][0])


