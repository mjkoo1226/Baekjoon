import sys
input = sys.stdin.readline

n, m, b = map(int, input().split())
land = []

for _ in range(n):
    land.extend(map(int, input().split()))

time = [0] * 257
h = 0

for g in range(257):
    block = b
    for i in land:
        if i <= g:
            time[g] += g - i
            block -= g - i
        else:
            time[g] += 2 * (i - g)
            block += i - g
    if block >= 0 and time[g] <= time[h]:
        h = g

print(time[h], h)