import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())
MOD = c

def square(num, exp):
    if exp == 1:
        return num % MOD

    if exp % 2 == 0:
        half = square(num, exp//2)
        return half * half % MOD
    else:
        return num * square(num, exp - 1) % MOD

print(square(a, b))