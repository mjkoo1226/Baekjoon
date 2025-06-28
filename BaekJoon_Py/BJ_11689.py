import math

N = int(input())
d = 2
gesu = {}

while d * d <= N:  # 1부터 sqrt(N)까지 반복
    while N % d == 0:
        if d in gesu:
            gesu[d] += 1
        else:
            gesu[d] = 1
        N //= d
    d += 1

if N > 1:
    gesu[N] = 1

answer = 1
for soinsu, cnt in gesu.items():
    answer *= soinsu ** cnt - soinsu ** (cnt - 1)

print(answer)