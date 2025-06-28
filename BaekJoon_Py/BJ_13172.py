import sys
import math
input = sys.stdin.readline

MOD = 1000000007

n = int(input())
answer = 0

def square(num, exp):
    if exp == 1:
        return num

    if exp % 2 == 0:
        half = square(num, exp//2)
        return half * half % MOD
    else:
        return num * square(num, exp - 1) % MOD

def geeyakmod(boonja, boonmo):
    return boonja * square(boonmo, MOD-2) % MOD

for i in range(n):
    a, b = map(int, input().split())
    
    gcd = math.gcd(a, b)
    a //= gcd
    b //= gcd
    
    answer += geeyakmod(b, a)
    answer %= MOD

print(answer)