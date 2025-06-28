import sys
input = sys.stdin.readline

N = int(input())
s = list(map(int, input().split()))
s.sort()

min = float('inf')

L = 0
R = 0

top = N - 1
bottom = 0
answer = 0

while bottom < top:
        total = s[bottom] + s[top]
        chai = abs(total)

        if chai < min:
            min = chai
        elif chai == min:
            L = s[bottom]
            R = s[top]
            answer = chai
            break

        if total < 0:
            bottom += 1
        elif total > 0:
            top -= 1
        else:
            bottom += 1
            top -= 1

print(answer)
print(L, R)
