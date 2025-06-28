import sys
input = sys.stdin.readline

n = int(input())
human = []

for i in range(n) :
    kg, cm = map(int, input().split())
    human.append((kg, cm))

for i in human :
    rank = 1
    for j in human :
        if i[0] < j[0] and i[1] < j[1] :
            rank += 1
    print(rank, end = " ")