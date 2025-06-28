import sys
input = sys.stdin.readline

n = int(input())
house = [[0, 0, 0] for _ in range(n)]

for i in range(n):
    house[i] = list(map(int, input().split()))

first_red = [0] * n
first_green = [0] * n
first_blue = [0] * n

first_red[0] = house[0][0]
first_green[0] = house[0][1]
first_blue[0] = house[0][2]

for i in range(1, n):
    first_red[i] = house[i][0] + min(first_green[i - 1], first_blue[i - 1])
    first_green[i] = house[i][1] + min(first_red[i - 1], first_blue[i - 1])
    first_blue[i] = house[i][2] + min(first_green[i - 1], first_red[i - 1])

ans = min(first_blue[n - 1], first_green[n - 1], first_red[n - 1])
print(ans)