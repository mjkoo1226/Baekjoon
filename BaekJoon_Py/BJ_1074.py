import sys
input = sys.stdin.readline

n, r, c = map(int, input().split())

def calcZ(n, r, c):
    if n == 0:
        return 0

    result = 0

    if c >= 2 ** (n - 1) and r >= 2 ** (n - 1):
        result += 3 * 4 ** (n - 1)
        return result + calcZ(n - 1, r - 2 ** (n - 1), c - 2 ** (n - 1))
    elif c >= 2 ** (n - 1) and r < 2 ** (n - 1):
        result += 4 ** (n - 1)
        return result + calcZ(n - 1, r, c - 2 ** (n - 1))
    elif c < 2 ** (n - 1) and r >= 2 ** (n - 1):
        result += 2 * 4 ** (n - 1)
        return result + calcZ(n - 1, r - 2 ** (n - 1), c)
    else:
        return calcZ(n - 1, r, c)
    
print(calcZ(n, r, c))