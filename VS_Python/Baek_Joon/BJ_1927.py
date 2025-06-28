import sys
import heapq
input = sys.stdin.readline

hip = []

t = int(input())
for _ in range(t):
    x = int(input())
    if x == 0:
        if hip:
            print(heapq.heappop(hip))
        else:
            print("0")
    else:
        heapq.heappush(hip, x)