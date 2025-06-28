import sys
input = sys.stdin.readline

MOD = 1000000007

def mod_pow(base, exp, mod):
    result = 1
    while exp:
        if exp % 2:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def mod_inv(x, mod):
    return mod_pow(x, mod - 2, mod)

def sum_of_divisors(n, m):
    answer = 1

    exponent = 0
    while n % 2 == 0:
        exponent += 1
        n //= 2
    if exponent:
        power = mod_pow(2, exponent * m + 1, MOD) - 1
        answer = (answer * power % MOD) * mod_inv(2 - 1, MOD) % MOD

    i = 3
    while i * i <= n:
        exponent = 0
        while n % i == 0:
            exponent += 1
            n //= i
        if exponent:
            power = mod_pow(i, exponent * m + 1, MOD) - 1
            answer = (answer * power % MOD) * mod_inv(i - 1, MOD) % MOD
        i += 2 

    if n > 1:
        power = mod_pow(n, m + 1, MOD) - 1
        answer = (answer * power % MOD) * mod_inv(n - 1, MOD) % MOD

    return answer

n, m = map(int, input().split())

print(sum_of_divisors(n, m))
