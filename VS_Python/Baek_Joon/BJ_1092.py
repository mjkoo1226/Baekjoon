import sys
input = sys.stdin.readline

crane_num = int(input())
crane_kg = list(map(int, input().split()))
box_num = int(input())
box_kg = list(map(int, input().split()))

crane_kg.sort(reverse=True)
box_kg.sort(reverse=True)

time = 0

if max(box_kg) > max(crane_kg):
    time = -1
else:
    while box_kg:
        for crane in crane_kg:
            if box_kg and crane < box_kg[-1]:
                continue
            for box in box_kg:
                if crane >= box:
                    box_kg.remove(box)
                    break
        time += 1

print(time)
