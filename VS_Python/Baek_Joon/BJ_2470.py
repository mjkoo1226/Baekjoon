import sys
import math
input = sys.stdin.readline

n = int(input())
liq = list(map(int, input().split()))
liq.sort()

head = 0
rear = n - 1
min = math.inf
answer = [liq[head], liq[rear]]

while(head < rear):
    if abs(liq[head] + liq[rear]) < min:
        answer = [liq[head], liq[rear]]
        min = abs(liq[head] + liq[rear])
    
    if liq[head] + liq[rear] < 0:
        head += 1
    elif liq[head] + liq[rear] > 0:
        rear -= 1
    else:
        answer = [liq[head], liq[rear]]
        break

print(*answer)